void TestString_Memory(const string &data,string &out_data) {
	cout << "data =  " << data << endl;
	cout<<"data.size()  "<<data.size() << endl;
	out_data.resize(2048);
	cout << "(long long)out_data.data() addr:  " << (long long)out_data.data() << endl;

}

int main()
{
	string str_one;
	str_one.resize(1024);
	auto data = const_cast<char*>(str_one.data());
	memset(data,'A', 5);
	cout<< str_one<<" \n" << sizeof(str_one) << endl;
	//TestString_Memory(str_one);

	string out_str;
	TestString_Memory(str_one, out_str);
	cout << str_one << " \n  sizeof(out_str) :" << sizeof(out_str) << endl;
	cout << "(long long)out_data.data() addr:  " << (long long)out_str.data() << endl;


	return 0;
}

/////////////VECTOR

class XData
{
public:
	XData()
	{
		cout << "XData() XData() XData() " << endl;
	}

	~XData()
	{
		cout << "~XData() ~XData() ~XData()" << endl;
	}

	XData& operator = (const XData& d) {
		this->index = d.index; cout << "XData& operator =   " << index << endl; return *this;
	}

	XData(const XData& other) {
		this->index = other.index;
		cout << "XData(const XData& other)     " << endl;
	}


	int index{ 0 };
};

vector<XData> TestVector(vector<XData>& data) {
	cout << "data.data()  " << data.data() << endl;
	vector<XData> re;
	re.resize(3);
	cout << "data.data()  " << data.data() << endl;
	cout << "re.size()*sizeof(XData)  " << re.size()*sizeof(XData) << endl;
	return re;
}

int main() {

	vector<XData> vd;
	XData d;
		d.index = 1;
		vd.push_back(d);
		d.index = 2;
		vd.push_back(d);
		d.index = 3;
		vd.push_back(d);	
	auto rd =TestVector(vd);
	cout<<"vd.data()  " << rd.data() << endl;

	return 0;
}
