# CSVWriter
Simple c++ csv writer class
## How to use ?
#### write a single row
```
CSVWriter csv;
csv << "this" << "is" << "a" << "row";
cout << csv << endl;
```
output:
```
this;is;a;row
```

#### write multiple rows
```
CSVWriter csv;
csv.newRow() << "this" << "is" << "the" << "first" << "row";
csv.newRow() << "this" << "is" << "the" << "second" << "row";
cout << csv << endl;
```
output
```
this;is;the;first;row
this;is;the;second;row
```
#### auto row
When each row has a fixed number of colums, CSVWriter can add rows automatic. In this example, every row has 4 colums
```
CSVWriter csv;
csv.enableAutoNewRow(5);
csv << "this" << "is" << "the" << "first" << "row" << "this" << "is" << "the" << "second" << "row";
cout << csv << endl;
```
output
```
this;is;the;first;row
this;is;the;second;row
```
#### write csv to filesystem
```
CSVWriter csv;
csv.newRow() << "this" << "is" << "the" << "first" << "row";
csv.newRow() << "this" << "is" << "the" << "second" << "row";
csv.writeToFile("foobar.csv");
```
#### append csv to existing file
```
CSVWriter csv;
csv << "append" << "this" << "row" << "please" << ":)";
cout << csv.writeToFile("foobar.csv",true) << endl;
```
#### change seperator
```
CSVWriter csv(",");
csv << "this" << "is" << "a" << "row";
cout << csv << endl;
```
output:
```
this,is,a,row
```
#### merge two CSVWriters
```
CSVWriter csv_a;
CSVWriter csv_b;
csv_a << "this" << "comes" << "from" << "csv_a";
csv_b << "this" << "is" << "from" << "csv_b";
csv_b += csv_a;
cout << csv_b << endl;
```
output
```
this;is;from;csv_b
this;comes;from;csv_a
```
