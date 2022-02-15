import 'package:flutter/material.dart';

class FormPage extends StatefulWidget {
  String title;
   FormPage({this.title = "表单"}) ;

  @override
  _FormPageState createState() => _FormPageState();
}

class _FormPageState extends State<FormPage> {




  @override
  Widget build(BuildContext context) {
    return Scaffold(
      floatingActionButton: FloatingActionButton(child: Text('ooo'),
        onPressed: () {
          Navigator.of(context).pop();
        },

      ),
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: ListView(

        children: <Widget>[
          ListTile(
            title: Text('我是表单1'),
          ),
          ListTile(
            title: Text('我是表单2'),
          ),
          ListTile(
            title: Text('我是表单3'),
          )
        ],
      ),
    );
  }


}
