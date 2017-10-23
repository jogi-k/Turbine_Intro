#Winking Man

This is the relevant source code of the winking man, shown on the Turbine opening on 21-Oct-2017.

* It shows a sad face on the LED-Matrix.
* It listens to the Mikrophone.
* as soone as it detects a certain level on the analog port of the microphone it 
  * turns its face into smiling
  * winks with its arm, connected to a servo-motor
 
 
How to use?
* Connect a servo-motor ( I used a cheap SG 90) to analog port 1. 
* Attention: Most servos operate at 5-6V. Calliope will only provide 3.3 V. So if it does not work it might be due to this. I tried 2 different servos until I found one that did wrk with the small voltage.
* go to : http://pxt.calliope.cc/index.html 
* switch to JAvascript-Mode on top of the page
* Copy-Paste the provided Java-Script-Code here into the Javascript-Editor
* Now you can switch to normal Block-Mode
* Have fun...
