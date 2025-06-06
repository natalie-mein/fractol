## **FRACTOL**

<p align="center" width="100%">
    <img width="33%" src="https://github.com/Arcane-Jill/images/blob/main/fract-olm.png">
</p>

Fractol is one of three options for the first graphics projects at **Hive** Helsinki, which is a school in the 42 network. This is definitely near the top of 
the list of most fun projects. It was an amazing respite from push swa,, and the fact that you get some lovely output that's not just printouts n the terminal
is a bonus.
### **Description**
From the subject: *"You will use the school’s graphical library, the MiniLibX. This library was developed internally and includes basic necessary tools to open 
a window, create images and deal with keyboard and mouse events.
This will be an opportunity for you to become familiar with the MiniLibX library, discover or use the mathematical concept of complex numbers, explore computer graphics
optimization, and practice event handling."*

I used the MLX42 library instead of minilibx.

#### **Mandatory part**

**"Your program must offer the Julia set and the Mandelbrot set"**
<p align="center" width="100%">
    <img width="33%" src="https://github.com/Arcane-Jill/images/blob/main/mandelbrot-blue.png">
</p>

Mandelbrot fractal

<p align="center" width="100%">
    <img width="33%" src="https://github.com/Arcane-Jill/images/blob/main/julia-blue.png">
</p>
Julia fractal

#### **Bonus part**

The bonus part involved more fancy things with the mouse and also an extra fractal. I chose the burning ship fractal:
<p align="center" width="100%">
    <img width="33%" src="https://github.com/Arcane-Jill/images/blob/main/burning-ship-red.png">
</p>
Burning ship fractal

### **How to use**
#### Clone the repository
```
git clone git@github.com:natalie-mein/fractol.git fractol && cd fractol
```
#### Compile the program
```
make
```
or to see the burning ship fractals
```
make bonus
```

#### Usage
```
./fractol <name of fractal>
```
or 
```
./fractol_bonus <name of fractal>
```
If you just enter
```
./fractol
```
you will get the following message:
```
Error: Invalid arguments provided.

~~~~~~~~Available Fractals~~~~~~~~~~
	Please type:
mandelbrot or julia


For Julia, you may specify starting values
between -2.0 and 2.0. Remember to include
one decimal place.


Examples for Julia sets:
	-0.4	0.6
	0.285	0.01
	0	0.8
	-1.476	0
	-0.12	-0.77
```
or with bonus:
```
Error: Invalid arguments provided.

~~~~~~~~Available Fractals~~~~~~~~~~
	Please type:
mandelbrot, julia, or burning


For Julia, you may specify starting values
between -2.0 and 2.0. Remember to include
one decimal place.


Examples for Julia sets:
	-0.4	0.6

	0.285	0.01
	0	0.8

	-1.476	0
	-0.12	-0.77
```
