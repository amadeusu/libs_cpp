#ifndef ACOMPLEX_H
#define ACOMPLEX_H

#include <iostream>

typedef struct acomplex
{
    double rp; //real part
    double ip; //imagine part
} cmplx_t;


cmplx_t create_complex(double rp, double ip)
{
    cmplx_t complex;
    complex.rp = rp;
    complex.ip = ip;

    return complex;
}

cmplx_t operator + (cmplx_t const& first, cmplx_t const& second)
{
    cmplx_t sum;
    double rp = first.rp + second.rp;
    double ip = first.ip + second.ip;

    sum = create_complex(rp, ip);

    return sum;
}

cmplx_t operator - (cmplx_t const& first, cmplx_t const& second)
{
    cmplx_t sub;
    double rp = first.rp - second.rp;
    double ip = first.ip - second.ip;

    sub = create_complex(rp, ip);

    return sub;
}

cmplx_t operator * (cmplx_t const& first, cmplx_t const& second)
{
    cmplx_t mul;
    double rp = (first.rp * second.rp) - (first.ip * second.ip);
    double ip = (first.rp * second.ip) - (first.ip * second.rp);

    mul = create_complex(rp, ip);

    return mul;
}

cmplx_t operator / (cmplx_t const& first, cmplx_t const& second)
{
    cmplx_t divd;
    double rp = ((first.rp * second.rp) + (first.ip * second.ip)) / ((second.rp * second.rp) + (second.ip * second.ip));
    double ip = ((first.ip * second.rp) - (first.rp * second.ip)) / ((second.rp * second.rp) + (second.ip * second.ip));

    divd = create_complex(rp, ip);

    return divd;
}

void print_cmplx(cmplx_t const num)
{
    std::cout << num.rp << " + " << num.ip << "i";
}

#endif