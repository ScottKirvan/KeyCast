Overview
--------
Here's what I think I might want to do with this:

I think I may want to make this project just monitor the ini file, and when it sees an update, it reloads the ini and updates all of it's settings.  This way, any application, or number of applications, could make changes while the keycaster is running.

For example:  I want to do tutorial videos using unreal.  Unreal has a pretty good config system already, and I already have a plugin that has some features that I use for the tutorials, so I'm thinking I'll add a button to launch the keycaster and put all of the settings in the same utility plugin.

I will tend to notice that I don't have the keycaster on when I'm already in unreal, so making it so I don't have to get unreal out of the way and search for the keycaster would be nice -- plus, I could make any font size/color changes in the same spot.

KeyCast's own settings panel probably won't stay updated, so I may just decouple that -- maybe I could write a seperate, standalone settings app that is launched from the taskbar and just modifies and monitors that ini file itself.


TODO
----
- [ ] copy the screencast keys mouse behavior (the image, etc.)
- [ ] figure out what the different settings do, document them, and make their behavior clearer.
- [ ] change the defaults to something less gaudy
- [ ] clean up the code and document it inline as much as possible.
- [ ] hadcode and remove some of these settings
- [ ] add center alignment
- [ ] add mouse image plus mouse click overlay images
- [ ] change the repeating keys to "KEY x##" format
- [ ] lose the lower case letters - go all upper
- [ ] we can lose the "mouse up/down" stuff if we have an image that shows the mouse activity
- [ ] lose the carriage return every time you hit space - hold on this idea - I want to see how the screen actually looks when using unreal - maybe it makes sense to keep it?  like tabbing between stuff?  maybe this is a setting... like even make it so each key gets it's own line?
- [ ] align left, center, right
- [ ] add an x, y offset (let it be negative, don't let it crash)

In Progress
-----------
- [ ] .

Done ✓
------
- [X] .  jsf  kjf skljsdf jklj

Not Gonna Do ✓
---------------
- [X] .