# Spotify API endpoint
$authEndpoint = "https://accounts.spotify.com/api/token"

# Spotify client ID and secret
$clientId = "your_client_id"
$clientSecret = "your_client_secret"

# Request an access token
$encodedAuth = [System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes("$($clientId):$($clientSecret)"))
$authResponse = Invoke-RestMethod -Method POST -Uri $authEndpoint -Headers @{Authorization = "Basic $encodedAuth"} -ContentType "application/x-www-form-urlencoded" -Body "grant_type=client_credentials"

# Get the access token
$accessToken = $authResponse.access_token
$userId = $authResponse.user_id

# Read musiclist.txt file
$musiclist = Get-Content -Path "C:\path\to\musiclist.txt"

# Create a new playlist
$playlistName = "My MP3 Playlist"
$playlistDescription = "A playlist created from my MP3 files"
$playlist = Invoke-RestMethod -Method Post -Uri "https://api.spotify.com/v1/users/$userId/playlists" -Body (@{name=$playlistName;description=$playlistDescription} | ConvertTo-Json) -Headers @{Authorization = "Bearer $accessToken"}

foreach($line in $musiclist){
    # Split the line into an array
    $songInfo = $line -split " - "
    $artist = $songInfo[0]
    $songTitle = $songInfo[1]
    # Search for the track on Spotify
    $track = Invoke-RestMethod -Method GET -Uri "https://api.spotify.com/v1/search?q=artist:$artist%20track:$songTitle&type=track" -Headers @{Authorization = "Bearer $accessToken"}
    # Add the track to the new playlist
    Invoke-RestMethod -Method Post -Uri "https://api.spotify.com/v1/playlists/$($playlist.id)/tracks?uris=$($track.tracks.items[0].uri)" -Headers @{Authorization = "Bearer $accessToken"}
}
