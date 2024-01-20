from nltk.tokenize import sent_tokenize
import argparse
import pdftotext
argparser = argparse.ArgumentParser()
argparser.add_argument("fileinput", help="PDF Name")
def getListOfTextFromPdf(fileinput):
    with open(fileinput, "rb") as f:
        pagesAsListOfText = pdftotext.PDF(f)
    return pagesAsListOfText

def translateEachTextToTarget(pagesOfText, outputfile):
    index = 1
    outputfile="{}tr.txt".format(outputfile[:-4])
    result_file = open(outputfile, "w")
    for Text in pagesOfText:
        result_file.write("Page {}".format(index))
        result_file.write("\n---------\n")
        Text=Text.replace('\n', ' ').replace('\r', '')
        for x in sent_tokenize(Text):
            print(x)
            x=" ".join(x.split())
            if len(x)<2:
                continue
            result_file.write("{}.\n".format(x))
        result_file.write("\n\n")
        index += 1
    result_file.close()

args = argparser.parse_args()
pagesOfText = getListOfTextFromPdf(args.fileinput)
translateEachTextToTarget(pagesOfText, args.fileinput)

