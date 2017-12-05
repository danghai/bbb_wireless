# BeagleBone Black Wireless

Experiments, Learning and Sharing done at BeagleBone Black Wireless

* [bbb-arm](https://github.com/danghai/bbb_wireless/tree/master/bbb-arm) :Bare metal code for BBB

* [bbb-driver](https://github.com/danghai/bbb_wireless/tree/master/bbb-driver) : Linux Kernel Device Driver

### Install Linux Header for bbb

Check the version: 

```
	debian@beaglebone:~$ uname -r
	4.4.97-bone20	
```

Install: 

```
	wget https://raw.github.com/gkaindl/beaglebone-ubuntu-scripts/master/bb-get-rcn-kernel-source.sh
	chmod +x bb-get-rcn-kernel-source.sh 
	./bb-get-rcn-kernel-source.sh 
	sudo apt-get install linux-headers-4.4.97-bone20 
```
