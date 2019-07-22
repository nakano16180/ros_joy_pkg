## ps4用のjoyコンを使うパッケージ

### joy_twist使用時の注意
/src/の中のjoy_twist.cppはそのままでは使えません。  
まずはコントローラー操作用のパッケージをインストール。  

```
$ sudo apt-get install ros-kinetic-joy
$ sudo apt-get install python-pip
$ sudo pip install ds4drv
```

これで準備は完了。コントローラーの動作確認は以下の通り。  

```
$ sudo ds4drv
$ roslaunch ros_joy_pkg ros_joy.launch
$ rostopic echo joy
```

### turtlebotの操作方法
端末を3つ開く  

```
$ sudo ds4drv
$ roslaunch ros_joy_pkg ros_joy.launch
$ roslaunch turtlebot_bringup minimal.launch
```

コントローラーのL2、R2で回転  
○ボタンを押しながら左スティックで前後左右の移動が可能
