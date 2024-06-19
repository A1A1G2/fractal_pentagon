#pragma once
#include <atomic>
#include <math.h>

#define arial_relative_path "/home/aag/Desktop/codes/SFML_SandBox/fractal_pentagon/Utils/Fonts/arial.ttf"

//Preprocessed Macros
#ifdef DEBUG
#define dbgprint(x) std::cout << x << std::endl
#else
#define dbgprint(x)
#endif

#define deg2rad(x) (x * M_PI / 180)
#define rad2deg(x) (x * 180 / M_PI)

template <typename T>
struct position{
    T x;
    T y;
};
