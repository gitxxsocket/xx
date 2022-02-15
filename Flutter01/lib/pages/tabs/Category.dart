

import 'package:flutter/material.dart';
import '../Form.dart';

class CategoryPage extends StatefulWidget {
  const CategoryPage({Key? key}) : super(key: key);

  @override
  _CategoryState createState() => _CategoryState();
}

class _CategoryState extends State<CategoryPage> {
  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      mainAxisAlignment: MainAxisAlignment.center,
      children: <Widget>[
        ElevatedButton(

          onPressed: () {
            Navigator.of(context).push(
              MaterialPageRoute(builder: (context)=>FormPage( title: "xxxx"))
            );
          },
          child: Text('跳转到表单并传值'),
        ),
      ],
    );
  }
}
