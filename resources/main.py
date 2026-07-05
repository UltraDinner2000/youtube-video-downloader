import yt_dlp
import sys
import os

url = sys.argv[1]
path = sys.argv[2]
format = sys.argv[3]

ffmpegPath = os.path.join(os.path.dirname(__file__), "ffmpeg", "bin")

if format == "video":
    ydl_opts = {
        'format_sort': ['ext:mp4:m4a'],
        'remux_video': 'mp4',
        'outtmpl': os.path.join(path, '%(title)s.%(ext)s'),
        'format': 'bestvideo+bestaudio/best',
        'ffmpeg_location': ffmpegPath,
    }
elif format == "audio":
    ydl_opts = {
        'outtmpl': os.path.join(path, '%(title)s.%(ext)s'),
        'format': 'bestaudio/best',
        'ffmpeg_location': ffmpegPath,
        'postprocessors': [{
            'key': 'FFmpegExtractAudio',
            'preferredcodec': 'mp3',
            'preferredquality': '192',
        }]
    }


with yt_dlp.YoutubeDL(ydl_opts) as ydl:
    ydl.download([url])