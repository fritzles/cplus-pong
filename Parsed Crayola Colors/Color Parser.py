
inFile = open('crayolaColors.txt','r')

curLine = ''
curLinePieces = []

name = []
rgb = []

while (inFile.readline() != ''):
    curLine = inFile.readline()

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
outFile = open('crayolaColorsStruct.txt','w')

for i in range(0, len(name)):
    outFile.write("color " + name[i] + " { " + rgb[i] + " }\n")

outFile.close()
    
