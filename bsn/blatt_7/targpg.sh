tar -c -z   "$1" | gpg -c > "$1.tar.gz.gpg"
