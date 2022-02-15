import 'package:flutter/material.dart';

class Setting extends StatefulWidget {
  const Setting({Key? key}) : super(key: key);

  @override
  _SettingState createState() => _SettingState();
}

class _SettingState extends State<Setting> {
  @override
  Widget build(BuildContext context) {
    return ListView(children: <Widget>[
      ListTile(title: Text("xxxxxxxxxx"),),
      ListTile(title: Text("xxxxxxxxxx1"),),
      ListTile(title: Text("xxxxxxxxxx2"),),
      ListTile(title: Text("xxxxxxxxxx3"),),
      ListTile(title: Text("xxxxxxxxxx4"),),
      ListTile(title: Text("xxxxxxxxxx5"),),
      ListTile(title: Text("xxxxxxxxxx6"),),
      ListTile(title: Text("xxxxxxxxxx7"),),
    ],);
  }
}
