*This project has been created as part of the 42 curriculum by juperrin and mperrine.*

## Description

The goal of this project is to recreate a mini Ray Tracing engine.

Q : What's Ray Tracing ?

R : Ray Tracing is the simulation of the light behavior in a 3D scene (2D sometimes).

Q : How does it works ?

R : Usually, light is emitted from a light source, bounces on some objects, and comes to our eyes. But that's not the way we do Ray Tracing because it is not optimized, we would compute a lot of unnecessary things. What we do instead, is casting a ray from our eye (the camera here) and we make it do the invert way. That way, we only render what we need.

## Instructions

Here is all the instructions you can do to build and execute the project :

- Compilation :
```bash
make
```
or
```bash
make all
```
- Execution :
```bash
./minirt <example.rt>
```
- To clean the files :
```bash
make fclean
```
- To clean and compile at the same time :
```bash
make re
```

## Resources

The apprehend and develop the project we used mainly the series of books : [Ray Tracing in One Weekend](https://raytracing.github.io/)

We also used the work of [Sebastian Lague](https://github.com/SebLague), especially the Ray Tracing videos he made :
- https://youtu.be/Qz0KTGYJtUk
- https://youtu.be/C1H4zIiCOaI
- https://youtu.be/wA1KVZ1eOuA

AI was used to see how some mathematical calculations like ray collision with a cylinder or a plane works, and for 3D space rotation and translation, because we didn't wanted to use matrixes and quaternions.