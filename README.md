# metadata-extractor-mp3
This C script extracts metadata from MP3 files.

## Features:

Extracts commonly used metadata fields like artist, album, title, year, genre, etc.
Optionally extracts album cover art (embedded as PNG)
Supports ID3v2 tags
Outputs extracted data in a human-readable format

### Requirements:

C compiler


Installation:
```bash
 gcc -o metadata-extractor metadata-extractor.c
```

Usage:
```bash
./metadata-extractor [OPTIONS] <MP3_FILE>...
Options:

-a: Extract and save album art (PNG format)
-h: Display help message
-v: Verbose output (show extracted data for each field)
```
Example:
```bash
./metadata-extractor -a song1.mp3 
```
If the -a option is used, it will also extract and save the album art for each song.

Output:

The script will output the following metadata fields for each MP3 file:

* Artist
* Album
* Title
* Year
* Genre

Improve user interface and output formatting
Contributing:

Contributions are welcome! Feel free to fork the repository and submit pull requests.