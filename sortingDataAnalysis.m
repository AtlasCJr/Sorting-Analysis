clc, clearvars;

% Data: Array Length, Bubble, Selection, Heap, Insertion, Quick
data = [
    1000, 1493, 931.24, 96.56, 501.08, 55.04;
    1100, 1783, 1083, 108.1, 591.88, 65.94;
    1210, 2146, 1316, 128.28, 747.08, 67.96;
    1331, 2623, 1585, 136.00, 929.22, 77.76;
    1464, 3187, 1928, 156.88, 1928, 87.84;
    1610, 4003, 2428, 187.56, 1360, 95.56;
    1771, 4624, 2783, 210.04, 1560, 106.92;
    1948, 5567, 3433, 252.04, 1969, 120.04;
    2143, 6719, 4145, 276.14, 1988, 130.68;
    2357, 8189, 4961, 341.96, 2444, 159.72;
    2593, 9848, 5966, 387.28, 3422, 163.72;
    2853, 12439, 7291, 494.89, 4929, 204.32;
    3138, 14549, 8658, 539.50, 5995, 236.78;
    3452, 17568, 10659, 414.50, 7426, 293.70;
    3797, 21581, 12975, 567.68, 8828, 348.60;
    4177, 26055, 15479, 601.72, 10599, 386.88;
    4594, 30995, 18694, 573.08, 13623, 345.00;
    5054, 37905, 22251, 675.08, 15597, 396.12;
    5559, 47112, 27075, 720.18, 17605, 394.72;
    6115, 55435, 32737, 900.76, 19153, 452.88;
    6727, 66339, 39783, 927.76, 22093, 498.56;
    7400, 80796, 47612, 1360.62, 2263, 485.92;
    8140, 99276, 57675, 1127.00, 33980, 705.86;
    8954, 114505, 69662, 856.52, 41921, 762.92;
    9849, 145728, 84236, 10432.16, 49511, 861.96;
    10834, 177249, 102316, 1502.36, 61458, 1219.92;
    11918, 214549, 124690, 1706.72, 73939, 1339.74;
    13109, 259841, 151555, 1970.42, 85994, 1702.16;
    14420, 316695, 181078, 2180.04, 104801, 2119.36;
    15862, 386661, 216061, 2638.98, 123720, 2591.92;
    17448, 472702, 257411, 3019.84, 146320, 3186.16;
    19193, 578987, 306131, 3195.81, 180424, 3580.92;
    21112, 715862, 365951, 3852.21, 202100, 4048.00;
    23223, 851849, 443484, 6834.48, 232366, 4616.96;
    25547, 966312, 531649, 16801.00, 295100, 4154.16;
    28102, 1045600, 639649, 14870.00, 338465, 4949.27;
    30912, 1206492, 767291, 17653.00, 394250, 5373.17;
    34003, 1291600, 921222, 11201.00, 442770, 6026.99;
    37404, 1505525, 1106339, 10201.00, 510050, 6869.16;
    41144, 1810725, 1336673, 11775.00, 581600, 7731.95;
    45259, 2152210, 1625160, 19395.00, 678350, 8536.96;
    49785, 2633665, 1987681, 16032.00, 786800, 9437.45;
    54763, 3091200, 2421898, 13770.00, 879400, 10849.00;
    60240, 3766000, 2951543, 22500.00, 997675, 11071.00;
    66264, 8168000, 3796200, 22690.00, 1121560, 11238.00;
];

x = data(:, 1);
bubble = data(:, 2);
selection = data(:, 3);
heap = data(:, 4);
insertion = data(:, 5);
quick = data(:, 6);


figure;
hold on;

subplot(2, 19, [1, 9]);
hold on;
plot(x, bubble, '-o', 'DisplayName', 'Bubble Sort');
plot(x, selection, '-x', 'DisplayName', 'Selection Sort');
plot(x, heap, '-s', 'DisplayName', 'Heap Sort');
plot(x, insertion, '-d', 'DisplayName', 'Insertion Sort');
plot(x, quick, '-^', 'DisplayName', 'Quick Sort');
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title('Sorting Algorithm Experiment');
subtitle("Normal Scale");
legend('Location', 'northwest');
grid on;
hold off;

subplot(2, 19, [11, 19]);
hold on;
plot(x, bubble, '-o', 'DisplayName', 'Bubble Sort');
plot(x, selection, '-x', 'DisplayName', 'Selection Sort');
plot(x, heap, '-s', 'DisplayName', 'Heap Sort');
plot(x, insertion, '-d', 'DisplayName', 'Insertion Sort');
plot(x, quick, '-^', 'DisplayName', 'Quick Sort');
set(gca, 'YScale', 'log');
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title('Sorting Algorithm Experiment');
subtitle("Logarithmic Scale");
legend('Location', 'northwest');
grid on;
hold off;



n = linspace(0, x(length(x)) * 1.1, 100);
options = optimset('Display', 'off');
initial_guess = [1, 1];
SQ_model = @(p, x) p(1) * (x - p(2)).^2;
LOG_model = @(p, x) p(1) * (x - p(2)) .* log2(x - p(2));

%Bubble
error_func = @(p) sum((bubble - SQ_model(p, x)).^2);
params = fminsearch(error_func, initial_guess, options);
a = params(1);
b = params(2);

subplot(2, 19, [20, 22]);
plot(n, a * (n - b).^2, 'DisplayName', 'Least Square');
hold on;
plot(x, bubble, 'DisplayName', 'Data');
hold off;
grid on;
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title("Bubble Sort", 'Units', 'normalized', 'Position', [0.5, 1.15, 0]);
subtitle(sprintf('t(n) = %.4f * (n - %.4f)^2', a, b), 'Units', 'normalized', 'Position', [0.5, 1.1, 0]);
legend('Location', 'northwest');

%Selection
error_func = @(p) sum((selection - SQ_model(p, x)).^2);
params = fminsearch(error_func, initial_guess, options);
a = params(1);
b = params(2);

subplot(2, 19, [24, 26]);
plot(n, a * (n - b).^2, 'DisplayName', 'Least Square');
hold on;
plot(x, selection, 'DisplayName', 'Data');
hold off;
grid on;
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title("Selection Sort", 'Units', 'normalized', 'Position', [0.5, 1.15, 0]);
subtitle(sprintf('t(n) = %.4f * (n - %.4f)^2', a, b), 'Units', 'normalized', 'Position', [0.5, 1.1, 0]);
legend('Location', 'northwest');

%Heap
error_func = @(p) sum((heap - LOG_model(p, x)).^2);
params = fminsearch(error_func, initial_guess, options);
a = params(1);
b = params(2);

subplot(2, 19, [28, 30]);
plot(n, a * ((n - b) .* log2(n - b)), 'DisplayName', 'Least Square');
hold on;
plot(x, heap, 'DisplayName', 'Data');
hold off;
grid on;
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title("Heap Sort", 'Units', 'normalized', 'Position', [0.5, 1.15, 0]);
subtitle(sprintf('t(n) = %.4f * (n - %.4f) * log2(n - %.4f)', a, b, b), 'Units', 'normalized', 'Position', [0.5, 1.1, 0]);
legend('Location', 'northwest');

%Insertion
error_func = @(p) sum((insertion - SQ_model(p, x)).^2);
params = fminsearch(error_func, initial_guess, options);
a = params(1);
b = params(2);

subplot(2, 19, [32, 34]);
plot(n, a * (n - b).^2, 'DisplayName', 'Least Square');
hold on;
plot(x, insertion, 'DisplayName', 'Data');
hold off;
grid on;
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title("Insertion Sort", 'Units', 'normalized', 'Position', [0.5, 1.15, 0]);
subtitle(sprintf('t(n) = %.4f * (n - %.4f)^2', a, b), 'Units', 'normalized', 'Position', [0.5, 1.1, 0]);
legend('Location', 'northwest');

%Quick
error_func = @(p) sum((quick - LOG_model(p, x)).^2);
params = fminsearch(error_func, initial_guess, options);
a = params(1);
b = params(2);

subplot(2, 19, [36, 38]);
plot(n, a * ((n - b) .* log2(n - b)), 'DisplayName', 'Least Square');
hold on;
plot(x, quick, 'DisplayName', 'Data');
hold off;
grid on;
xlabel('Array Length');
ylabel('Sorting Time (µs)');
title("Quick Sort", 'Units', 'normalized', 'Position', [0.5, 1.15, 0]);
subtitle(sprintf('t(n) = %.4f * (n - %.4f) * log2(n - %.4f)', a, b, b), 'Units', 'normalized', 'Position', [0.5, 1.1, 0]);
legend('Location', 'northwest');



