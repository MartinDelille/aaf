#
# Generate an html table from a change log (output of cvs2cl.pl)
#
# $ cat ChangeLog | awk -f build/history/cl2html.awk > changelog.html
#
# Tim Bingham
#
BEGIN {
  date = "";
  printHeader();
}

/^[0-9]+-[0-9]+-[0-9]+/ {
  if (date != "") {
#    printf("[%s]\n", entrytext);
    gsub("\t", " ", entrytext);
    entrytext = trim(entrytext, 3);
    f = split(entrytext, fields, ":");
#    printf("[%d]\n", f);
#    for (i = 1; i <= f; i++) {
#      printf("[%d : \"%s\"]\n", i, fields[i]);
#    }
    /* We should have at least a file name and a comment */
    if (f < 2) {
      printf("cl2html : Error near \"%s\"\n", entrytext) | "cat 1>&2";
      exit(1);
    }
    if (match(fields[1], "/$")) {
      /* The first field is a directory */
      dir = fields[1];
      files = trim(fields[2], 1);
      cs = 3; /* Start of comment */
    } else {
      /* The first field is not a directory */
      dir = "";
      files = fields[1];
      cs = 2; /* Start of comment */
    }
    /* put comment back together - undo split on ":" */
    comments = trim(fields[cs], 1);
    for (i = cs + 1; i <= f; i++) {
      comments = comments ":" fields[i]
    }

    printf("[dir      = \"%s\"]\n", dir);
    printf("[files    = \"%s\"]\n", files);
    printf("[comments = \"%s\"]\n", comments);
    /* print previous table row */
    printRow(date, name, files, comments, color);
  }
  /* build new table row */
  date = $1;
  name = $3;
  entrytext = "";
  files = "";
  comments = "";
  color = "#FFCCCC";
}

/^\t/ {
  /* accumulate the text of this entry */
  entrytext = entrytext $0;
}

END {
  if (date != "") {
    /* print last table row */
    printRow(date, name, files, comments, color);
  }
  printTrailer();
}

function printHeader() {
  printf("\
<TABLE width=\"100%%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\n");
}

function printRow(date, name, files, comments, color) {
  printf("\
<TR>\n\
  <TD width=\"50\" height=\"22\">%s</TD>\n\
  <TD height=\"22\" width=\"112\" bgcolor=\"%s\">%s</TD>\n\
  <TD colspan=\"2\" height=\"22\" bgcolor=\"%s\">%s</TD>\n\
  <TD colspan=\"3\" height=\"22\" bgcolor=\"%s\">%s</TD>\n\
</TR>\n",
    date, color, name, color, files, color, comments);
}

function printTrailer() {
  printf("</TABLE>\n");
}

# Remove first n characters of s
function trim(s, n) {
  return substr(s, n + 1, length(s) - n);
}
