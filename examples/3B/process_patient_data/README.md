Compile with:
```sh
$ g++ -c compute_mean.cpp -o compute_mean.o
$ g++ -c load_data.cpp -o load_data.o
$ g++ -c stats.cpp -o stats.o
```

Then link with:
```sh
$ g++ load_data.o compute_mean.o stats.o -o compute_mean
```

