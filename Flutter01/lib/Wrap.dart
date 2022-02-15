import 'package:flutter/material.dart';

class MyApp1 extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('xx Demo'),
        ),
        body: LayoutDemo(),
      ),
    );
  }
}

class MyButton extends StatelessWidget {
  final String text;

  const MyButton(
    this.text, {
    Key? key,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ElevatedButton(
      onPressed: () {},
      child: Text(this.text),
    );
  }
}

class LayoutDemo extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 600,
      width: 400,
      color: Colors.pinkAccent,
      child: Wrap(
        spacing: 10,
        runSpacing: 12,
        runAlignment: WrapAlignment.center,
        children: <Widget>[
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
          MyButton("text"),
        ],
      ),
    );
  }
}
