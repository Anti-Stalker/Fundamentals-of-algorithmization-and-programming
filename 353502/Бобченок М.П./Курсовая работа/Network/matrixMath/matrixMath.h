//
// Created by u on 22.02.24.
//

#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#pragma once

#ifndef N_MATRIXMATH_H
#define N_MATRIXMATH_H

const int TYPE = 1;

bool equal(float x, float y);

bool consistsOfZeros(std::vector<float> &a, int numOfZeros = 2);

void create(int n, std::vector<float> &a);

void create(int n, int m, std::vector<std::vector<float> > &a);

void zero(std::vector<float> &a);

void zero(std::vector<std::vector<float> > &a);

void zero(std::vector<std::vector<std::vector<float> > > &a);

void fastZero(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<float> > &b, std::vector<std::vector<float> > &c);

void zeroFrom(int n, std::vector<std::vector<float> > &a);

void randTo(std::vector<int> &a, int max);

void rand(std::vector<float> &a, int type = TYPE);

void rand(std::vector<std::vector<float> > &a, int type = TYPE);

void rand(std::vector<std::vector<std::vector<float> > > &a, int type = TYPE);

int numOfZeros(std::vector<int> &a);

std::pair<int, int> shape(std::vector<std::vector<float> > &a);

int shape(std::vector<float> &a);

void print(std::vector<int> &a);

void print(std::vector<float> &a);

void print(std::vector<std::vector<float> > &a);

void print(std::vector<std::vector<std::vector<float> > > &a);

void print(int a);

void print(std::pair<int, int> a);

void mult(std::vector<float> &a, float x);

void mult(std::vector<std::vector<float> > &a, float x);

void mult(std::vector<std::vector<std::vector<float> > > &a, float x);

void mult(std::vector<float> &a, std::vector<float> &b);

void mult(std::vector<float> &a, std::vector<int> &b);

void mult(std::vector<float> &a, std::vector<float> &b, std::vector<float> &c);

void mult(std::vector<float> &a, std::vector<float> &b, std::vector<std::vector<float> > &c, bool ZERO = false);

void mult(std::vector<float> &a, std::vector<std::vector<float> > &b, std::vector<float> &c, bool T = false);

void mult(std::vector<std::vector<float> > &a, std::vector<std::vector<float> > &b, std::vector<std::vector<float> > &c);

float sum(std::vector<float> &a);

void sum(std::vector<float> &a, float &b);

void sum(std::vector<float> &a, std::vector<float> &b);

void minus(std::vector<std::vector<float> > &a, std::vector<std::vector<float> > &b);

void minus(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<std::vector<float> > > &b);

void minusMult(std::vector<std::vector<float> > &a, std::vector<std::vector<float> > &b, float x);

void minusMult(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<std::vector<float> > > &b, float x);

void fastMinusMult(std::vector<std::vector<std::vector<float> > > &a, std::vector<std::vector<std::vector<float> > > &b, float x, std::vector<std::vector<float> > &c, std::vector<std::vector<float> > &d);

#endif //N_MATRIXMATH_H
