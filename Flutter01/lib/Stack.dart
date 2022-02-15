import 'package:flutter/material.dart';

class MyApp1 extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: (Scaffold(
        appBar: AppBar(
          title: Text("xxxx Demo.."),
        ),
        body: HomeContent(),
      )),
    );
  }
}

class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
        height: 400,
        width: 300,
        color: Colors.pinkAccent,
        child: Stack(
          // alignment: Alignment.center,

          children: <Widget>[
            Positioned(
              left: 10,
              // alignment: Alignment.topLeft,
              child: Icon(
                Icons.home,
                size: 40,
                color: Colors.white,
              ),
            ),
            Positioned(
              bottom: 0,
              left: 100,
              child: Icon(
                Icons.search,
                size: 40,
                color: Colors.orange,
              ),
            ),
            Positioned(
              right: 0,
              child: Icon(
                Icons.settings,
                size: 40,
                color: Colors.blue,
              ),
            ),
          ],
        ),
      ),
    );
  }
}

/*
class HomeContent extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Stack(
        alignment: Alignment(0, -1),
        children: <Widget>[
          Container(
            height: 400,
            width: 300,
            color: Colors.pinkAccent,
          ),
          Text("text1 ...xxxx333",
              style: TextStyle(fontSize: 40, color: Colors.brown)),
          Text("text2 ...xxxx222",
              style: TextStyle(fontSize: 40, color: Colors.brown)),
          Text("text3 ...xxxx111111",
              style: TextStyle(fontSize: 40, color: Colors.brown)),
        ],
      ),
    );
  }
}
*/
