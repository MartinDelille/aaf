###############################################################################
#
# The contents of this file are subject to the AAF SDK Public
# Source License Agreement (the "License"); You may not use this file
# except in compliance with the License.  The License is available in
# AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
# Association or its successor.
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
# the License for the specific language governing rights and limitations
# under the License.
#
# The Original Code of this file is Copyright 1998-2002, Licensor of the
# AAF Association.
#
# The Initial Developer of the Original Code of this file and the
# Licensor of the AAF Association is Avid Technology.
# All rights reserved.
#
###############################################################################

#
# Generate an html table from a change log (output of cvs2cl.pl)
#
# $ cvs2cl.pl --stdout -rx:y > Changes-x-y.log
#
# $ cat Changes-x-y.log | awk -f cl2html.awk colormap > Changes-x-y.html
#
#
# Author : Tim Bingham - Tim_Bingham@avid.com
#
BEGIN {
  if (ARGC != 2) {
    printf("Error : Usage : %s <colormap>\n", ARGV[0]) | "cat 1>&2";
    exit 1;
  }

  if ((TAG1 == "") || (TAG2 == "")) {
    TITLE = "cvs change log";
  } else {
    TITLE=sprintf("Log of changes made between %s and %s", TAG1, TAG2);
  }
  entrytext = "";
  createColorMap(ARGV[1]);
  delete ARGV[1]; # Otherwise this would be the next input file
  printHeader();
}

/^[0-9]+-[0-9]+-[0-9]+/ {
  if (entrytext != "") {
    entry(entrytext);
  }
  /* Build new table row */
  date = $1;
  gsub("-", "/", date);
  name = $3;
  entrytext = "";
  files = "";
  comments = "";
}

/^\t/ {
  /* Accumulate the text of this entry */
  entrytext = entrytext $0;
}

END {
  if (entrytext) {
    entry(entrytext);
  }
  printTrailer();
}

function printKey() {
  printf("<h1>Key</h1>\n");
  printf("<table>\n");
  printf("<tr><th>Color</th><th>Component</th></tr>\n");
  for (i in names) {
    printf("<tr>\n");
    printf("<td bgcolor=\"%s\">&nbsp;</td>\n", colors[names[i]]);
    printf("<td>%s</td>\n", i);
    printf("</tr>\n");
  }
  printf("</table>\n");
}

function printHeader() {
  "date" | getline date
  "echo $USER$USERNAME" | getline user
  "hostname" | getline computer
  printf("\
<!-- -->\n\
<!-- This file was generated on %s by user %s -->\n\
<!-- on system %s using cl2html.awk -->\n\
<!-- If you edit this file your changes may be lost. -->\n\
<!-- -->\n", date, user, computer);

  printf("<html>\n");
  printf("<head>\n");
  printf("<title>%s</title>\n", TITLE);
  printf("</head>\n");
  printf("<body>\n");
  printKey();
  printf("<h1 align=center>%s</h1>\n", TITLE);
  printf("\
<table>\n\
<tr>\n\
  <th>Date</th>\n\
  <th>Developer</th>\n\
  <th>Files</th>\n\
  <th>Checkin comment</th>\n\
</tr>\n");
}

function printRow(date, name, files, comments, color) {
  printf("\
<tr>\n\
  <td>%s</td>\n\
  <td bgcolor=\"%s\">%s</td>\n\
  <td bgcolor=\"%s\">%s</td>\n\
  <td bgcolor=\"%s\">%s</td>\n\
</tr>\n",
    date, color, name, color, files, color, comments);
}

function printTrailer() {
  printf("</table>\n");
  printf("</body>\n");
  printf("</html>\n");
}

# Remove first n characters of s
function trim(s, n) {
  return substr(s, n + 1, length(s) - n);
}

function createColorMap(file) {
  component = 0;
  line = 0;
  while (getline < file > 0) {
    line = line + 1;
    if ($1 != "#") {
      if (NF != 0) {
        if ($1 == "color") {
          if (component == 1) {
            printf("Error : \"%s\", line %s - illegally placed color.\n",
                   file, line) | "cat 1>&2";
            exit 1;
          }
          if ($2 in colors) {
            printf("Error : \"%s\", line %s - duplicate color \"%s\".\n",
                   file, line, $2) | "cat 1>&2";
            exit 1;
          } else {
            colors[$2] = "#" $3
          }
        } else if ($1 == "component") {
          if (component == 0) {
            if ($2 in names) {
              printf("Error : \"%s\", line %s - duplicate name \"%s\".\n",
                     file, line, $2) | "cat 1>&2";
              exit 1;
            } else {
              name = $2;
            }
            if ($3 in colors) {
              color = colors[$3];
              names[name] = $3;
            } else {
              printf("Error : \"%s\", line %s - unknown color \"%s\".\n",
                     file, line, $3) | "cat 1>&2";
              exit 1;
            }
            component = 1;
          } else {
            printf("Error : \"%s\", line %s - unmatched component.\n",
                   file, line) | "cat 1>&2";
            exit 1;
          }
        } else if ($1 == "end") {
          if (component == 1) {
            component = 0;
          } else {
            printf("Error : \"%s\", line %s - unmatched end.\n",
                   file, line) | "cat 1>&2";
            exit 1;
          }
        } else if ($1 == "default") {
          if (component == 1) {
            printf("Error : \"%s\", line %s - illegally placed default.\n",
                   file, line) | "cat 1>&2";
            exit 1;
          }
          default="#" $2;
        } else if ($1 == "#") {
          # ignore comment
        } else {
          if (component == 1) {
            map[$1] = color;
          } else {
            printf("Error : \"%s\", line %s - unknown item \"%s\".\n",
                   file, line, $1) | "cat 1>&2";
            exit 1;
          }
        }
      } # else ignore empty line
    } # else ignore comment
  }
#  for (i in colors) {
#    printf("%s %s\n", i, colors[i]);
#  }
#  for (i in map) {
#    printf("%s %s\n", i, map[i]);
#  }
#  for (i in names) {
#    printf("%s %s\n", i, names[i]);
#  }
}

function rowcolor(files) {
  result = default;
  /* Get first file */
  split(files, fns, ",");
  ff = fns[1];
#  printf("<!--[%s]-->\n", ff);
  /* Match directory of file to a color */
  len = 0;
  for (x in map) { /* Arbitrary order */
    if (match(ff, "^" x)) {
      if (RLENGTH > len) {
        /* Take longest match */
        len = RLENGTH;
        result = map[x];
      }
    }
  }
  return result;
}

function entry(entrytext) {
#  printf("<!--[%s]-->\n", entrytext);
  gsub("\t", " ", entrytext);
  entrytext = trim(entrytext, 3);
  f = split(entrytext, fields, ":");
#  printf("<!--[%d]-->\n", f);
#  for (i = 1; i <= f; i++) {
#    printf("<!--[%d : \"%s\"]-->\n", i, fields[i]);
#  }
  /* We should have at least a file name and a comment */
  if (f < 2) {
    printf("cl2html : Error near \"%s\"\n", entrytext) | "cat 1>&2";
    exit(1);
  }
  if (match(fields[1], "/$")) {
    /* The first field is a directory */
    dir = fields[1];
    files = trim(fields[2], 1);
    gsub(" ", "", files);
    n = split(files, names, ",");
#    printf("<!--[%d]-->\n", n);
#    for (i = 1; i <= n; i++) {
#      printf("<!--[%d : \"%s\"]-->\n", i, names[i]);
#    }
    /* Insert directory names */
    files = dir names[1];
    for (i = 2; i <= n; i++) {
      files = files ", " dir names[i];
    }
    cs = 3; /* Start of comment */
  } else {
    /* The first field is not a directory */
    dir = "";
    files = fields[1];
    cs = 2; /* Start of comment */
  }
  /* Put comment back together - undo split on ":" */
  comments = trim(fields[cs], 1);
  for (i = cs + 1; i <= f; i++) {
    comments = comments ":" fields[i]
  }

  color = rowcolor(files);

#  printf("<!--[dir      = \"%s\"]-->\n", dir);
#  printf("<!--[files    = \"%s\"]-->\n", files);
#  printf("<!--[comments = \"%s\"]-->\n", comments);
  /* Print previous table row */
  printRow(date, name, files, comments, color);
}
