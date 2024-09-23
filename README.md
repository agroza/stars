# stars
Stars screensaver for MS-DOS

## Synopsis

I've always wanted to write my own screensaver ever since I first saw Starry Night of Norton Commander and the original Dos Navigator screensavers programmed by Andy Zabolotny. I guess the year was 1995.
Since I still use (a self-improved variant of) Dos Navigator on my retro computers, and I had some spare time, I finally decided to make my own re-interpretation of the Starry Night screensaver.

And to give some more meaning to this project, I decided to write it completely in assembly language. As a challenge, I wanted the compiled program to be as tiny as possible, while adding some slight improvements over the original work.
Thus, I added various star sequences (newborn, inflated, shining, exploding, extinct). Once a star becomes extinct, the program will eventually recycle the dead star and remove it from the night sky, effectively making space for a new star.

The executable file is only 358 bytes. The code can still be optimized, but I'm happy with the results.
I've added this screensaver to Dos Navigator by changing the extension from ```.COM``` to ```.SS``` and set the timeout to 5 minutes.

Here's a screenshot with the small program animating the virtual night sky.

![stars](https://github.com/agroza/stars/blob/master/images/stars-night-sky.jpg?raw=true)
