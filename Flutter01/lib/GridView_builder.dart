import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'ListData.dart';

class MyApp1 extends StatelessWidget {
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('xxxxxxxxxxx Demo'),
        ),
        body: HomeContent(),
      ),
    );
  }
}

class HomeContent extends StatelessWidget {
  List<Widget> _getListData2() {
    var tempList = listData.map((value) {
      return Container(
        child: Column(
          children: [
            Image.network(value["imageUrl"]),
            SizedBox(height: 10),
            Text(
              value['title'],
              textAlign: TextAlign.center,
              style: TextStyle(fontSize: 30),
            )
          ],
        ),
        decoration: BoxDecoration(
            border: Border.all(
                color: Color.fromRGBO(233, 233, 233, 0.9), width: 1)),
      );
    });
    return tempList.toList();
  }

  List<Widget> _getListData1() {
    List<Widget> list = [];

    for (var i = 0; i < 30; i++) {
      list.add(Container(
        alignment: Alignment.center,
        child: Text(
          "xxxxxxxx$i",
          style: TextStyle(color: Colors.white, fontSize: 30),
        ),
        color: Colors.pinkAccent,
      ));
    }
    return list;
  }

  Widget _getListData(context, index) {
    return Container(
      child: Column(
        children: <Widget>[
          Image.network(listData[index]["imageUrl"]),
          SizedBox(height: 12),
          Text(
            listData[index]['title'],
            textAlign: TextAlign.center,
            style: TextStyle(fontSize: 20),
          )
        ],
      ),
      decoration: BoxDecoration(
          border:
              Border.all(color: Color.fromRGBO(233, 233, 233, 0.9),
                  width: 1)),
    );
  }

  @override
  Widget build(BuildContext context) {
    return GridView.builder(
      itemCount: listData.length,
      itemBuilder: this._getListData,
      gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
          mainAxisSpacing:10,
          crossAxisSpacing:10,
          crossAxisCount: 2
      ),
    );

    /*GridView.count(
      crossAxisCount: 2,
      crossAxisSpacing: 20,
      mainAxisSpacing: 20,
      // childAspectRatio: 0.7,
      padding: EdgeInsets.all(10),
      children: this._getListData(),
    );*/
  }
}
