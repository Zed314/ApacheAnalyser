# ApacheAnalyser

NAME

	ApacheAnalyser - manual page for ApacheAnalyser v1.0



SYNOPSIS

	./analog [OPTION...] filename.log



OPTIONS

	-g filename.dot

		Generate GraphViz file using analysed data

		To generate an image use the command: dot -Tpng -o filename.png filename.dot

		Check manual pages for "dot" for more information



	-e

		Exclude from analysis all documents that have an image, css or javascript extension



	-t hour

		Include in the analysis the documents that where logged between [hour, hour+1] only
