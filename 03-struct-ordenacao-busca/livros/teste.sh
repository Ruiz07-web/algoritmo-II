gcc livros.c -o livros || exit 1
for t in teste*.txt; do
    echo "===== $t ====="
    ./livros < "$t"
    echo
done
