//
// Created by Aleksey Leshchankin on 22.11.2022.
//

#pragma once

void HeapSort (int* arrayToSort, int arrayToSort_size, unsigned long& cmp, unsigned long& asg, int& time);
void heapify (int* arrayToSort, int arrayToSort_size, int i, unsigned long& cmp, unsigned long& asg);