# High Performance Computing (HPC) Labs 

This repository contains my solutions to High Performance Computing (HPC) lab tasks. Each lab explores parallel programming techniques.

---

## **Module Overview**

The **High Performance Computing** module focuses on writing efficient, parallel programs that leverage multi-core processors to improve performance.  
Techniques covered include:
- OpenMP for shared-memory parallelism
- Parallel loops, synchronization, and matrix operations
- Performance measurement and optimization

---

## **Labs Overview**

###  **Lab 3: Introduction to OpenMP**

This lab introduces **OpenMP** — a powerful API for parallel programming in C/C++. It covers:

- **Parallel regions**: Basic thread creation
- **Vector addition**: Parallelizing element-wise operations
- **Matrix multiplication**: Accelerating matrix math with multiple threads
- **Shared resources**: Handling race conditions using synchronization mechanisms like `#pragma omp critical`

We compared serial and parallel versions of the code, measured performance using OpenMP timers, and observed significant speedup with multiple threads.

