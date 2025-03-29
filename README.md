# Line Follower Bot #
Autonomous Line follower created by students of RoboTech Club at National Institute of Science Education and Research in an attempt for participating in competitions.

# Time Line #
Start of project : 14th Jan 2025
Date of Competition : 6th Feb 2025

# Problem Statement #
There is a track which has a black line and rest of the area is white in the track. There will be a starting point and stoping point and many lines will be there which connects the start and stop point. The bot is supposed to follow the black line and there will be many challenge like unexpected turns and different ways in which the bot will be misguided from the end line. The bot has to avoid the challenges and reach the stop point as fast as possible.The Bot is allowed to be touched only 5 times without getting penalty in time.

# Concept/Theory #
The IR sesor is a device which is capable of emitting infrared lights to sense some aspect of the surroundings and can be employed to detect the motion of an object. This light propagates through the air and hits an object, after that the light gets reflected in the photodiode sensor. The above concept is used to detech the change in the black line and then process accordingly. Expermentally we saw that whenever a sesor detect black line then it gives output as 1 and whenever it detects white region then it gives output 0.

By using the above concept we will use to maneuver out bot. Whenever it detects a black line it will follow it by using Proportional–integral–derivative controller Algorithm.

## Taking Input ##
We take the input using our 6 IR sensor device : 

- The input is taken from the digital pins of the device
- The input is given in form of binary 1 or 0
- 1 means detection of black line and 0 means white area detected
- We define a function called read() in Arduino which digitalRead all the pins

