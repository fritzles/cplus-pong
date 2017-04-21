
infile = open('crayolaColors.txt','r')

curLine = ''
curLinePieces = []

name = []
rgb = []

while (infile.readline() != ''):
    curLine = infile.readline()

    # extract and clean name
    curLinePieces = curLine.split('\t')
    curLinePieces[0] = curLinePieces[0].replace(" ", "_")
    name.append(curLinePieces[0])

    # extract and clean rgb values
    curLinePieces[2] = curLinePieces[2].replace('\n','')
    curLinePieces[2] = curLinePieces[2].replace(',',', ')
    curLine = curLinePieces[2]
    rgb.append(curLine)


# format and save values in new file
outfile = open('crayolaColorsStruct.txt','w')

# generate constants
outfile.write("const int NUM_CRAYOLA_COLORS = " + str(len(name)) + ";\n\n")

# generate array of color rgb values
outfile.write("color CRAYOLA_COLOR[NUM_CRAYOLA_COLORS] = { ")
for i in range(0, len(name)):
    if (i % 6 == 0 or i % 6 == 3):
        outfile.write("\n            ")

    outfile.write("color { " + rgb[i] + " }")

    if (i != len(name)-1):
        outfile.write(", ")

outfile.write("\n            };")
outfile.write("\n\n")

# generate array of color names
outfile.write("std::string COLOR_NAME[NUM_CRAYOLA_COLORS] = { ")
for i in range(0, len(name)):
    if (i % 6 == 0 or i % 6 == 3):
        outfile.write("\n            ")

    outfile.write('"' + name[i] + '"')
    
    if (i != len(name)-1):
        outfile.write(", ")

outfile.write("\n            };")

outfile.close()
    
