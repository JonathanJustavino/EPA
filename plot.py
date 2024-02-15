import matplotlib.pyplot as plt
import numpy as np
import matplotlib.cm as cm

c_performance = [
    0.003306,
    0.022071,
    0.079687,
    0.184774,
    0.342723,
    0.568598,
    0.919196,
    2.44623,
    3.43211,
    3.908014,
    8.7446,
    11.827671,
    17.272457,
    20.264881,
    28.264881,
    32.130428,
    39.950871,
    45.26786,
    61.883278,
    69.62573,
]

java_performance = [
    0.05,
    0.08,
    0.054,
    0.126,
    0.243,
    0.429,
    0.705,
    1.22,
    1.588,
    2.137,
    9.934,
    13.291,
    18.883,
    26.116,
    31.251,
    40.075,
    51.362,
    61.166,
    74.852,
    91.424,
]

fortran_performance = [
    0.005,
    0.035,
    0.114,
    0.297,
    0.566,
    0.991,
    1.583,
    3.202,
    3.539,
    4.912,
    7.851,
    12.037,
    14.442,
    18.336,
    23.851,
    34.878,
    38.746,
    42.47,
    50.507,
    74.255,
]

javascript_performance = [
    0.005,
    0.04,
    0.119,
    0.318,
    0.703,
    1.21,
    2.038,
    4.458,
    5.408,
    8.881,
    13.14,
    17.232,
    23.708,
    32.67,
    48.046,
    53.206,
    60.172,
    73.982,
    87.018,
    130.358,
]

dimensions = [
    100,
    200,
    300,
    400,
    500,
    600,
    700,
    800,
    900,
    1000,
    1100,
    1200,
    1300,
    1400,
    1500,
    1600,
    1700,
    1800,
    1900,
    2000,
]

#430753
#6dcb61
#30728d
#fce540

def render(performance, dimensions, color, label_text):
    plt.plot(performance, dimensions, color, marker='o',label='{}'.format(label_text))

render(c_performance, dimensions, '#430753', 'C')
render(java_performance, dimensions, '#6dcb61', 'Java')
render(fortran_performance, dimensions, '#30728d', 'Fortran')
render(javascript_performance, dimensions, '#fcad40', 'JavaScript')

plt.axis([0, 200, 100, 2100])
plt.ylabel('Dimension')
plt.xlabel('Time in s')
plt.legend()
plt.show()
