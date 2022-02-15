import 'package:flutter/material.dart';

class MyApp1 extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('xx Demo'),
        ),
        body: HomePage1(),
      ),
    );
  }
}

class HomePage1 extends StatefulWidget {
  const HomePage1({Key? key}) : super(key: key);

  @override
  _HomePage1State createState() => _HomePage1State();
}

class _HomePage1State extends State<HomePage1> {
  List _list = [];

  @override
  Widget build(BuildContext context) {
    return ListView(
      children: <Widget>[
        Column(
          children: this._list.map((value) {
            return ListTile(
              title: Text(value),
            );
          }).toList(),
        ),
        SizedBox(
          height: 100,
        ),
        ElevatedButton(
            onPressed: () {
              setState(() {
                this._list.add('1');
                this._list.add('2');
              });
            },
            child: Text(' button 1 '))
      ],
    );
  }
}

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  int countNum = 0;
  List list = [];

  @override
  Widget build(BuildContext context) {
    return

      ListView(
      children: <Widget>[
        Column(
          children: this.list.map((value) {
            return ListTile(
              title: value,
            );
          }).toList(),
        ),
        SizedBox(
          height: 100,
        ),
        ElevatedButton(
            onPressed: () {
              this.countNum++;
              setState(() {
                this.countNum++;
              });
            },
            child: Text('button'))
      ],
    );
  }
}

/*
class HomePage extends StatelessWidget {
  int countNum = 1;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: <Widget>[
        SizedBox(
          height: 200,
        ),
        Text('data1 ${this.countNum}'),
        SizedBox(
          height: 20,
        ),
        ElevatedButton(
            onPressed: () {
              this.countNum++;
              print(this.countNum);
            },
            child: Text('button'))
      ],
    );
  }
}
*/
