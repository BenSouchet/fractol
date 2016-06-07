# Fractol

Fdf is a program developped for my learning course at 42 school for the exploration of fractals.
<img align="center" src="http://i.imgur.com/SRtIgLN.png" width="100%" />
Several options are available (see [Keyboard shortcuts](https://github.com/Raiden-kazua/Fractol#keyboard-shortcuts) section for more infos) :
* Zoom and unzoom
* Change the number of iterations
* Move the current fractal
* Rotate by step of 90°
* Edit the display color
* Navigate between the three fractals
* Edit the shape of the fractal with the position of the mouse (only available with the fractal Julia)

## Install & launch
```bash
git clone https://github.com/Raiden-kazua/Fractol ~/Fractol
cd ~/Fractol && ./fractol Julia
```
You have to launch the program with a parameter. this is the name of the fractal you would like to open at the execution of the program. Parameter(s) as to be the name(s) of valid fractal (Julia, Mandelbrot or Tricorn).<br />

Example :

Open the Mandelbrot fractal ⇣
```bash
./fractol Mandelbrot
```
## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="100%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="100%" align="center" cellpadding="0">
<span style="width:50px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program (aka quit/exit)</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Reset all the changes made for this map</td>
<td valign="top" align="center"><kbd>&nbsp;clear&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the display color of the current map (aka change color)</td>
<td valign="top" align="center"><kbd>&nbsp;shift&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the global size of the map (aka zoom)</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the global size of the map (aka unzoom)</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the map to the up (aka move up)</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the map to the down (aka move down)</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the map to the left (aka width move left)</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the map to the right (aka move right)</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Clockwise rotation on the X axe</td>
<td valign="top" align="center"><kbd>&nbsp;W&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Counter clockwise rotation on the X axe</td>
<td valign="top" align="center"><kbd>&nbsp;S&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Clockwise rotation on the Y axe</td>
<td valign="top" align="center"><kbd>&nbsp;D&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Counter clockwise rotation on the Y axe</td>
<td valign="top" align="center"><kbd>&nbsp;A&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Clockwise rotation on the Z axe</td>
<td valign="top" align="center"><kbd>&nbsp;E&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Counter clockwise rotation on the Z axe</td>
<td valign="top" align="center"><kbd>&nbsp;Q&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Previous preloader map*</td>
<td valign="top" align="center"><kbd><center>&nbsp;page&nbsp;<br /> up</center></kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Next preloader map*</td>
<td valign="top" align="center"><kbd>&nbsp;page&nbsp;<br /> down</kbd></td>
</tr>
</tbody>
</table>
*Only available if you lauched the program with more than one map.
## Contact & contribute
If you want to contact me, or fix/improve Polygons, just send me a mail at **bsouchet@student.42.fr**
