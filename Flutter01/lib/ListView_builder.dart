import 'package:flutter/material.dart';
// import 'GridView_builder.dart';
import 'Paddiing_Row.dart';
void main() => runApp(MyApp1());

class MyApp extends StatelessWidget {
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
  List list1 = [];

  HomeContent() {
    for (var i = 0; i < 30; i++) {
      this.list1.add(ListTile(
            title: Text("hahah $i xx"),
          ));
    }
  }

  List listData = [
    {
      "title": "a1",
      "author": "aa1",
      "imageUrl": "https://www.itying.com/images/flutter/1.png",
    },
    {
      "title": "b2",
      "author": "bb2",
      "imageUrl": "https://www.itying.com/images/flutter/2.png",
    },
    {
      "title": "c3",
      "author": "cc3",
      "imageUrl": "https://www.itying.com/images/flutter/3.png",
    },
  ];

  List<Widget> _getData1() {
    var tempList = listData.map((value) {
      return ListTile(
        leading: Image.network(value["imageUrl"]),
        title: Text(value["title"]),
        subtitle: Text(value["author"]),
      );
    });
    return tempList.toList();
  }

  List<Widget> _getData() {
    List<Widget> list = [];
    for (var i = 0; i < 20; i++) {
      list.add(ListTile(
        title: Text("  list ...$i"),
      ));
    }

    return list;
  }


  Widget _getListData(context, index){
    return ListTile(
      leading: Image.network(listData[index]["imageUrl"]),
      subtitle :Text(listData[index]["author"]),
      title: Text (listData[index]["title"]),
    );
  }

  @override
  Widget build(BuildContext context) {
    // TODO: implement build

    return ListView.builder(
      itemCount: listData.length,
      itemBuilder: this._getListData
    );

    /*ListView(
      children: this._getData1(),
    );*/
  }
}

//    https://www.itying.com/images/flutter/1.png

/*ListView(
      scrollDirection: Axis.horizontal,
      padding: EdgeInsets.all(20),
      children: <Widget>[
        Container(
          width: 180.0,
          height: 180.0,

          color: Colors.deepOrange,
        ),
        Container(
          width: 120.0,
          height: 120.0,
          color: Colors.brown,
        ),
        Container(
          width: 180.0,
          height: 180.0,
          color: Colors.pinkAccent,
        ),
        Container(
          width: 180.0,
          height: 180.0,
          color: Colors.green,
          child: ListView(
            children: <Widget>[
              Container(
                width: 180.0,
                height: 180.0,
                color: Colors.pinkAccent,
              ),
            ],
          )
        ),
      ],
    );
  }
}*/

/* ListView(padding: EdgeInsets.all(120), children: <Widget>[
      Image.network(
          'https://tse1-mm.cn.bing.net/th/id/R-C.35fddc7c529e0bd9a87f537c65e0e0fb?rik=djqpzg%2buPwRfAg&riu=http%3a%2f%2fpic.zsucai.com%2ffiles%2f2014%2f0627%2f0626wklmnmtiphone5bz2.jpg&ehk=QLP9lNEbHEhfqRdXC9HmjbfabcG0DhQJTK9F6l6CfQk%3d&risl=&pid=ImgRaw&r=0'),
      Container(
        child: Text('xxxxxxxxxxx',
        textAlign: TextAlign.center,style: TextStyle(fontSize: 30),),

      ),
      Image.network(
          'https://tse1-mm.cn.bing.net/th/id/R-C.35fddc7c529e0bd9a87f537c65e0e0fb?rik=djqpzg%2buPwRfAg&riu=http%3a%2f%2fpic.zsucai.com%2ffiles%2f2014%2f0627%2f0626wklmnmtiphone5bz2.jpg&ehk=QLP9lNEbHEhfqRdXC9HmjbfabcG0DhQJTK9F6l6CfQk%3d&risl=&pid=ImgRaw&r=0'),
      Image.network(
          'https://tse1-mm.cn.bing.net/th/id/R-C.35fddc7c529e0bd9a87f537c65e0e0fb?rik=djqpzg%2buPwRfAg&riu=http%3a%2f%2fpic.zsucai.com%2ffiles%2f2014%2f0627%2f0626wklmnmtiphone5bz2.jpg&ehk=QLP9lNEbHEhfqRdXC9HmjbfabcG0DhQJTK9F6l6CfQk%3d&risl=&pid=ImgRaw&r=0'),
      Image.network(
          'https://tse1-mm.cn.bing.net/th/id/R-C.35fddc7c529e0bd9a87f537c65e0e0fb?rik=djqpzg%2buPwRfAg&riu=http%3a%2f%2fpic.zsucai.com%2ffiles%2f2014%2f0627%2f0626wklmnmtiphone5bz2.jpg&ehk=QLP9lNEbHEhfqRdXC9HmjbfabcG0DhQJTK9F6l6CfQk%3d&risl=&pid=ImgRaw&r=0'),
      Image.network(
          'https://tse1-mm.cn.bing.net/th/id/R-C.35fddc7c529e0bd9a87f537c65e0e0fb?rik=djqpzg%2buPwRfAg&riu=http%3a%2f%2fpic.zsucai.com%2ffiles%2f2014%2f0627%2f0626wklmnmtiphone5bz2.jpg&ehk=QLP9lNEbHEhfqRdXC9HmjbfabcG0DhQJTK9F6l6CfQk%3d&risl=&pid=ImgRaw&r=0'),
    ]);
  }
}*/

/*ListTile(
          leading: Icon(
            Icons.settings,
            size: 60,
          ),
          title: Text(
            "xxxxxxxxxxxxxxxxxxxxx",
            style: TextStyle(fontSize: 28),
          ),
          subtitle: Text("1111111111111111111"),
        ),
        ListTile(
          leading: Image.network(
              'https://tse2-mm.cn.bing.net/th/id/OIP-C.8uVu-5b0wLZQVzx3vZwBQAHaNJ?pid=ImgDet&rs=1'),
          title: Text(
            "xxxxxxxxxxxxxxxxxxxxx",
            style: TextStyle(fontSize: 28),
          ),
          subtitle: Text("1111111111111111111"),
        ),
        ListTile(
          leading: Icon(Icons.home),
          title: Text(
            "xxxxxxxxxxxxxxxxxxxxx",
            style: TextStyle(fontSize: 28),
          ),
          subtitle: Text("1111111111111111111"),
        ),
        ListTile(
          leading: Icon(Icons.pages, color: Colors.pinkAccent),
          title: Text(
            "xxxxxxxxxxxxxxxxxxxxx",
            style: TextStyle(fontSize: 28),
          ),
          subtitle: Text("1111111111111111111"),
        ),
        ListTile(
          leading: Icon(Icons.settings),
          title: Text(
            "xxxxxxxxxxxxxxxxxxxxx",
            style: TextStyle(fontSize: 28),
          ),
          subtitle: Text("1111111111111111111"),
        ),
      ],
    );
  }
}*/

/*Center(
      child: Container(
        child: Image.network(
            'http://www.crystalradio.cn/data/attachment/forum/202202/11/133514b0xdnq4sr8r49n1s.jpg',
            alignment: Alignment.bottomCenter,
            colorBlendMode: BlendMode.luminosity,
            fit: BoxFit.fill),
        width: 600,
        height: 5500,
      ),
    );
  }
}
*/
