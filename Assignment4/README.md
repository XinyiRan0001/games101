GAMES101 Assignment 4 — Bézier Curve
Overview

This project implements Bézier curve rendering using the de Casteljau recursive algorithm.

Implemented features include:

Recursive Bézier curve evaluation
Interactive control point input
Bézier curve rendering
Anti-aliasing (Bonus)

The program allows users to click four control points and generates a smooth cubic Bézier curve in real time.

Features
1. Recursive Bézier Curve

Implemented the recursive de Casteljau algorithm inside:

recursive_bezier()

The algorithm recursively interpolates between neighbouring control points until only one point remains.

This final point lies on the Bézier curve.

2. Bézier Curve Rendering

Implemented inside:

bezier()

The program iterates through:

t = 0 → 1

with small steps and evaluates Bézier curve positions using the recursive algorithm.

The resulting curve is rendered in green.

3. Interactive Control Points

Users can place four control points using mouse clicks.

White points = control points
Green curve = Bézier curve

The first and last control points are the curve endpoints, while the middle points control the curve shape.

Anti-aliasing (Bonus)

Implemented anti-aliasing to smooth the Bézier curve edges.

Instead of coloring only a single pixel for each curve point, neighbouring pixels are also colored based on their distance to the curve.

Pixels closer to the curve receive higher intensity values, producing smoother visual results and reducing jagged edges.

Technologies
C++
OpenCV
Recursive Algorithms
How to Run

Build the project:

cmake --build .

Run:

.\Debug\BezierCurve.exe

Instructions:

Click four control points with the mouse
The Bézier curve will be generated automatically
The rendered image will be saved as:
my_bezier_curve.png
