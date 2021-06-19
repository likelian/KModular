#define KParameterSmoothingCoeff_Generic 0.04

#define KParameterSmoothingCoeff_Fine 0.002

const static double KM_pi = 3.14159265359;
const static double KM_2pi = 6.28318530718;

const static int maxBufferDelaySize = 28000;

inline float KM_linear_interp(float v0, float v1, float t)
{
    return (1 - t ) * v0 + t * v1;
}


inline double tanh_clip(double x)
{
    return x * (27 + x * x) / (27 + 9 * x * x);
}
