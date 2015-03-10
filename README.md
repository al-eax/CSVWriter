# CSVWriter
Simple c++ csv writer class
## How to use ?
#### write a single row
```
CSVWriter csv;
csv << "here" << "we" << "have" << 4 << "colums";
cout << csv
csv.writeToFile("foobar.csv")
```
this will create a csv file `foobar.csv` with `here;we;have;4;colums`

#### write multiple rows
```
CSVWriter csv;
csv.newRow() << "this" << "is" << "a" << "row";
csv.newRow() << "an" << "other" << "row" << "here";
cout << csv;
csv.writeToFile("foobar.csv");
```
this will create a csv file `foobar.csv` with 
```
this;is;a;row
an;other;row
```
#### auto row
When each row has a fixed number of colums, CSVWriter can add rows automatic. In this example, every row has 4 colums
```
CSVWriter csv;
csv.enableAutoNewRow(4);
csv << "this" << "is" << 1 << "row" << "this" << "is" << "another" << "row";
cout << csv;
csv.writeToFile("foobar.csv");
```
this will create a csv file `foobar.csv` with
```
this;is;1;row
this;is;another;row
```
