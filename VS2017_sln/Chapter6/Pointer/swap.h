#pragma once

// swap by reference
void swap(int& a, int& b);

// swap by value
void swap(int a, int b);

// swap by pointer
void swap(int* pa, int* pb);

// swap array pa == nullptr ,*pa -- ÎÞÐ§µÄ
void swap(int* pa, int* pb, int n);
