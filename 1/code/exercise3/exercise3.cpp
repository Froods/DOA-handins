//Code 1
sum = 0;                       // 1
for (i = 0; i < n; ++i) {
    ++sum;                     // 1
}                              // N * 1 + 1


//Code 2
sum = 0;                        // 1
for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
        ++sum;                  // 1
    }                           // Two loops meaning N * N
}                               // N^2 * 1 + 1

//Code 3
sum = 0;                            // 1
for (i = 0; i < n; ++i) {
    for (j = 0; j < n * n; ++j) {
        ++sum;                      // 1
    }                               // N * N^2 * 1 + 1
}

//Code 4:
sum = 0;                        // 1
for (i = 0; i < n; ++i) {
    for (j = 0; j < i; ++j) {
        ++sum;                  // 1
    }                           // ((N * N-1) / 2) * 1 + 1
}







