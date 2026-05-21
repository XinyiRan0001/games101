# GAMES101 — Computer Graphics Assignments

## Overview

This repository contains my implementations and experiments for the GAMES101 Computer Graphics course.

The projects cover fundamental topics in modern computer graphics, including:

- Rasterization
- Bézier Curves
- Texture Mapping
- Phong Shading
- Bump & Displacement Mapping
- Ray Tracing
- BVH Acceleration
- SAH Optimization
- Path Tracing
- Monte Carlo Integration
- Multi-threaded Rendering
- Physically Based Rendering (PBR)
- Rope Physics Simulation

The implementations were developed in C++ using OpenCV and OpenGL.

---

# Assignments

## Assignment 0 — Transformation & Rasterization

Implemented:

- Vector and matrix transformations
- Rotation matrices
- Translation matrices
- Homogeneous coordinates

Key concepts:

- Linear Algebra
- Coordinate Transformations
- Matrix Multiplication

---

## Assignment 1 — Triangle Rasterization

Implemented:

- Triangle rasterization
- MVP transformations
- Depth buffering
- Viewport transformation

Key concepts:

- Graphics Pipeline
- Screen Space Conversion
- Z-buffering

---

## Assignment 2 — MSAA & Anti-Aliasing

Implemented:

- Supersampling Anti-Aliasing (MSAA)
- Multi-sample rasterization
- Edge smoothing

Key concepts:

- Sampling Theory
- Anti-aliasing
- Coverage Testing

---

## Assignment 3 — Texture Mapping & Shading

Implemented:

- Phong shading
- Blinn-Phong shading
- Texture mapping
- Normal interpolation
- Bump mapping
- Displacement mapping
- Bilinear texture sampling

Key concepts:

- Lighting Models
- BRDF Basics
- Texture Filtering
- Surface Detail Simulation

---

## Assignment 4 — Bézier Curve

Implemented:

- Recursive de Casteljau algorithm
- Cubic Bézier curve evaluation
- Anti-aliasing for Bézier rendering

Key concepts:

- Curve Interpolation
- Recursive Geometry Algorithms
- Anti-aliasing

---

## Assignment 5 — Ray Tracing

Implemented:

- Ray-sphere intersection
- Ray-triangle intersection
- Diffuse shading
- Shadow testing
- Recursive ray tracing

Key concepts:

- Ray Casting
- Recursive Rendering
- Geometric Intersection Tests

---

## Assignment 6 — BVH & SAH Acceleration

Implemented:

- Bounding Volume Hierarchy (BVH)
- AABB intersection
- BVH traversal
- Surface Area Heuristic (SAH)

Key concepts:

- Spatial Acceleration Structures
- Ray Traversal Optimization
- Performance Optimization

### SAH Bonus

Implemented Surface Area Heuristic splitting for BVH construction.

The split position is selected by minimizing traversal cost:

```text
Cost = Ct + (SA(L) / SA(P)) * NL + (SA(R) / SA(P)) * NR
```

This improves traversal efficiency compared to naive midpoint splitting.

---

## Assignment 7 — Path Tracing & PBR

Implemented:

- Monte Carlo Path Tracing
- Direct Lighting
- Indirect Lighting
- Russian Roulette
- Global Illumination
- Multi-threaded Rendering
- Cook-Torrance Microfacet BRDF

Key concepts:

- Monte Carlo Integration
- Physically Based Rendering
- Global Illumination
- Importance Sampling

### Multi-threading Bonus

Applied multi-threading to ray generation using:

```cpp
std::thread
```

This significantly reduced rendering time.

### Microfacet Bonus

Implemented:

- GGX Distribution
- Schlick Fresnel
- Smith Geometry Term

to simulate physically-based glossy reflections.

---

## Assignment 8 — Rope Simulation

Implemented:

- Mass-spring rope system
- Semi-implicit Euler integration
- Explicit Verlet integration
- Hooke’s Law
- Damping
- Pinned constraints

Key concepts:

- Physics Simulation
- Numerical Integration
- Constraint Solving

---

# Technologies

- C++
- OpenCV
- OpenGL
- GLFW
- Monte Carlo Rendering
- Physically Based Rendering (PBR)
- BVH Acceleration
- Multi-threading

---

# Repository Structure

```text
games101/
│
├── Assignment0/
├── Assignment1/
├── Assignment2/
├── Assignment3/
├── Assignment4/
├── Assignment5/
├── Assignment6/
├── Assignment7/
├── Assignment8/
│
└── README.md
```

---

# Highlights

## Rendering

- Path Tracing
- Global Illumination
- Physically Based Rendering
- Microfacet BRDF
- BVH & SAH Optimization

## Physics

- Rope Simulation
- Verlet Integration
- Constraint-based Simulation

## Optimization

- BVH Acceleration
- Surface Area Heuristic
- Multi-threaded Rendering

---

# Learning Outcomes

Through these assignments, I explored:

- Modern rendering pipelines
- Physically-based rendering techniques
- Monte Carlo integration
- Ray tracing acceleration structures
- GPU/CPU rendering concepts
- Physics-based simulation
- Numerical integration methods

---

# Build

Most assignments can be built using:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

---

# Author

Developed as part of the GAMES101 Computer Graphics coursework.
