import 'package:flutter/material.dart';

class SearchPager extends StatefulWidget {

  final arguments;


  SearchPager({this.arguments});

  @override
  _SearchPagerState createState() => _SearchPagerState();
}

class _SearchPagerState extends State<SearchPager> {

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("搜索页面x ${widget.arguments}"),
      ),
      body: Text('搜索内容x'),
    );
  }
}
