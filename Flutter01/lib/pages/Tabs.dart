import 'package:flutter/material.dart';
import 'tabs/Home.dart';
import 'tabs/setting.dart';
import 'tabs/Category.dart';

class MyApp1 extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(home: MyApp3());
  }
}

class MyApp3 extends StatefulWidget {
  const MyApp3({Key? key}) : super(key: key);

  @override
  _MyApp3State createState() => _MyApp3State();
}

class _MyApp3State extends State<MyApp3> {


  int _currentIndex = 0;

  List _pageList = [
    Home(),
    Setting(),
    CategoryPage(),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('xx Demo'),
      ),
      body: this._pageList[this._currentIndex],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: this._currentIndex,
        onTap: (int index) {
          setState(() {
            this._currentIndex = index;
          });
        },
        iconSize: 50,
        fixedColor: Colors.pinkAccent,
        items: [
          BottomNavigationBarItem(icon: Icon(Icons.home), label: 'add'),
          BottomNavigationBarItem(
              icon: Icon(Icons.select_all), label: 'select'),
          BottomNavigationBarItem(
              icon: Icon(Icons.close_fullscreen), label: 'close'),
        ],
      ),
    );
  }
}
