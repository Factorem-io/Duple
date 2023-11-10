# Duple

![](https://github.com/Factorem-io/Duple/blob/main/Small%20Duple%20Gif.gif)

## Backstory and Product Definition

The Duple is a small dynamic desk accessory, the  idea was born after watching the Action Lab video where he created a crude version using a 3d printer and a variable speed turn table.   The extent of the Duple original idea was simply "what If I made a *really* nice version of that".  The premise is to mimic the atomic behavior of a Quadrupole Ion trap, but at the Macro Scale. Rotating a Saddle Curve at a very specific speed "traps" a ball placed in the curve.  There are also 3 build log videos for this project;

I go into detail on the mechanism of action (Math) and overal plan in the first video: [https://youtu.be/10STl1BM-Sc](https://youtu.be/10STl1BM-Sc)
The second video contains more actual doing. I write the Code, do the CAD, and begin circuit design. [https://youtu.be/1wiIylYVoeQ](https://youtu.be/1wiIylYVoeQ)
The Final video finished the project and brings this idea to life. There is about 900k lines of Gcode and 12 hours of machine time to create the curved piece. [https://youtu.be/2t_IWL_aRn4](https://youtu.be/2t_IWL_aRn4)
## Interesting Design Tid-bits
The details of how the Duple actually works is better explained in the video.  Essentially at the atomic scale you can "flap" and electric field to get a particle to stay in one place, you can emulate the "flapping" by rotating a static saddle curve, which is easier to do in the macro space.  There are a bunch of governing equations but the actual math is pretty forgiving on the weight of the ball, geometry of the saddle, etc.   Essentially you tune the speed for the system you ahve.  
### Mechanical Design
I knew from the start I wanted to use Walnut and Brass, they just look so cool together...  I played around a little bit with how all of the materials would go together in the context of the saddle curve before  landing on the brass inlays being horizontally incorporated into the spinning element.  I like how from the side the brass almost looks stationary and from the top it forms a series of gentle curves, and right in the middle there's a interesting looking parabolic X.  I think it's very visually interesting. 
The real challenge with making this project was machining the combination of brass and Walnut.  I ended up laminating the parts together with epoxy to form a blank. I then bolted that blank to an aluminum shaft in an effort to hold onto roughly the center of mass.  The challenge is I could really only "hold" onto wood. This is fine for when you're machining wood, but becomes a chatter nightmare when you want to machine the metal elements since they are harder than the walnut and push back harder than the wood.  This ended up meaning I just had to take things slow and machine over the course of 12 hours...  
### Electrical Design
This is the first ever "real" project I tackled creating a custom circuit board for. I screwed a lot of things up along the way but often that's the fastest way to learn the correct way.  Eventually I was able to create a working prototype. That being said, I have many regrets about my circuit design choice, I would not recommend anyone use my KICAD files without tweaking at least the package sizes if not more of the way the components were laid out.  
At the beginning of the project I had to decide how I wanted to spin the motor.  I could have used BLDC motors, a DC motor, Steppers...  Ultimately I decided on a stepper.  
My reasoning being; A BLDC requires a feedback loop and (relatively) complex driving circuitry, as well as code.  A DC motor is really easy to run but the rotation speed is voltage driven, since this is an RPM critical application and I wanted it to be either battery or USB powered (neither of which have a guaranteed voltage without some fiddling)
With a Stepper, I can command a speed with code and as long as the torque requirements are within spec the stepper will spin at that speed regardless of voltage and small perturbations, all without a feedback loop.  

In addition to the Stepper driver I have a potentiometer for fine tuning the motor speed and a light sensing resistor to turn the device on. 
### Software Design
There is a light sensor on the circuit board that "looks" for light.  When the ball is stored on the base, it blocks light and this is effectively "off"  when the user picks the ball up, the Light sensor sees the light and starts spinning the motor.  The motor is commanded to ramp up to the desired speed to avoid the device lurching up to speed.  That's pretty much it.  There's a Potentiometer to fine tune thee speed a little bit but the overall speed needs to be programed directly into the controller
### CAD Insight
This project was a good exercise in packaging efficiency.  I picked the flattest pancake stepper I could find, that pretty much set the minimum size of the Saddle.   I knew I wanted to Machine this on my PocketNC which has a maximum Build volume of ~ 4" x 4" x 4" so those set the upper and lower bound for the size.  Everything else was mostly eyeballed into place.  The saddle curve was approximated with some splines, the actual shape of the curve is pretty forgiving as long as the curvature transitions smoothly from positive to negative curvature.  
## Build Instructions
Since this is such a custom build when it comes to materials it's hard to give specific build instructions.  If you're interested in replicating the results I would recommend 3D printing everything. 

## Examples of Use
Gif or video of it in action

## Current State of Project
At this point the project is complete.  I have created what I had in my minds eye, and with that, the dopamine from pursuing this project has left me. 
## Future Plans
I don't have any future plans on a time table. 
One day I would like to make a version that is a little more user friendly 

### How to Contribute
The best way to contribute is going to be through discord, Please join the discord server and reach out with your examples.  I'd be happy add them to be base design if you have any cool ideas! 
### Where and how to ask for Help
Again Discord is likely the best place to reach me and the community. 

# Personal Skill's developed
This is the first project I tackled where I developed a Circuit board from scratch using KiCAD.  I loved the process and hope to do more of it in the future. It's also the first project I used Manim on so overall this was a huge learning experience



### [Sources/Inspo](https://github.com/Factorem-io/Duple/blob/main/README.md#sourcesinspo)

[https://sci-hub.se/https://doi.org/10.1139/p02-110](https://sci-hub.se/https://doi.org/10.1139/p02-110)

[https://sci-hub.se/https://doi.org/10.1119/1.4933206](https://sci-hub.se/https://doi.org/10.1119/1.4933206)

[https://sci-hub.se/https://doi.org/10.1119/1.17983](https://sci-hub.se/https://doi.org/10.1119/1.17983)

[https://youtu.be/1NBOsELakx4](https://youtu.be/1NBOsELakx4)
