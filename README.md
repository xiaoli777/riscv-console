# Documentation
### Introduction

My code of demo: https://github.com/xiaoli777/riscv-console/tree/ecs150project

My demo is comprised of 3 components:

- ./sim_xiaoli: the simulator which is used for loading the fireware and cartridge
- ./fw_xiaoli: the fireware which contains an example
- ./cart_xiaoli: the cartridge which is designed by phase 1



### sim_xiaoli

I do **NOT** know if I can reuse the professor's code. So, I just modified the simulator based on his code, which helped me understand how to design a simulator quickly.

![image-20210215121127679](.\img\simulator.png)

In this simulator, I set the button to w, a, s, d and u, i, j, k. Moreover, I have implemented the corresponding function for these buttons. Additionally, to make convenient for debugging, I also added debug mode on the right side.



### fw_xiaoli

![image-20210215121127679](.\img\firework.png)

After loading the fireware and pressing the PowerOn button, We can see a triangle on the screen. Now, we can use buttons: If we press the w, a, s and d, the cursor will move and leave the corresponding direction, like ^, <, > and v;  If we press the u, i, j and k, the cursor will print the corresponding letter. Also. we can see the debug mode will change after pressing the buttons.



### cart_xiaoli

For the cartridge, I only build a framework which contains the APIs designed by phase 1. In the next phase, I will implement all these APIs, and try to run it on the simulator.

