<!-- markdownlint-disable-file MD013 -->
<!-- markdownlint-disable-file MD014 -->

# NeoVim Files

- This directory is me or anyone else to look at for reference for future editing tasks.
- Contains the files I used to help create this repository.
- Contains examples of Neovim commands to perform complex editing tasks that saved a lot of time.

---

Each file {num}.txt correlates to command used at that {num}. I ran one command on each file after I made a copy of it. Which resulted in the next {num}.txt file.

1. `%s/^[0-9]\.[0-9].*\n\([0-9]\)/\1/g` *(I ran this command on file 1.txt which resulted in file 2.txt)*
2. `%s/^\([0-9]\)\.\([0-9]\)/\1-\2/g`
3. `%s/^$\n//g`
4. `%s/^\([0-9]-[0-9]*\).*$/\1/g`
5. `manual edit` No fancy commands to get to file 6
6. ``
