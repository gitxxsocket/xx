import 'package:flutter/material.dart';



class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      mainAxisAlignment: MainAxisAlignment.center,
      children: <Widget>[
        ElevatedButton(
          onPressed: () {
           Navigator.pushNamed(context, '/search',arguments:{"id":123} );
          },
          child: Text('跳转到搜索页'),
        ),
        SizedBox(
          height: 20,
        ),

      ],
    );
  }
}
