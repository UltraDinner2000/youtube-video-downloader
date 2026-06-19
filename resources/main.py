import yt_dlp
import sys

url = sys.argv[1]

with yt_dlp.YoutubeDL() as ydl:
    ydl.download([url])