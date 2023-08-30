### Note

**Forked from [brookhong/KeyCastOW](https://github.com/brookhong/KeyCastOW)**

Not a native English speaker, sorry for my grammar and spelling mistakes!

> What did I change？

A simple change:

Not create new message while keep mouse wheel scrolling

Reason:

I usually use *KeyCastOW* for presentations or meetings, and when i keep my mouse wheel scrolling up or down to turn pages, the messages would quickly cover the full screen. Then my content would be blocked, that’s kind of inconvenient. 

Compare：

<center>before：<img src="https://umeta.oss-cn-beijing.aliyuncs.com/blog/%E5%BD%95%E5%88%B6_2022_05_09_18_13_07_646_Moment.jpg" alt="录制_2022_05_09_18_13_07_646_Moment" width=25% /> &nbsp&nbsp after：<img src="https://umeta.oss-cn-beijing.aliyuncs.com/blog/%E5%BD%95%E5%88%B6_2022_05_09_18_10_29_243_Moment.jpg" alt="录制_2022_05_09_18_10_29_243_Moment" width=25% /> </center>


## build

```shell
msbuild /p:platform=win32 /p:Configuration=Release
```

Just run:  [keycastow.exe](keycastow.exe)  （on Windows）

## Credits
A huge thank you and all creds to [Brook Hong](https://brookhong.github.io/) and their [KeyCastOW](https://github.com/brookhong/KeyCastOW)
MIT License
Copyright (c) (2015) Brook Hong.  
Rubing Yang (2022).  
This code contains modifications by Scott Kirvan.  Modifications (c) (2023) Scott Kirvan  
All Rights Reserved  

_KeyCast_ is licensed under the [MIT License](LICENSE.md)
Copyright © [2015 Brook Hong](https://brookhong.github.io/)

Forked from [brookhong/KeyCastOW](https://github.com/brookhong/KeyCastOW)
