#!/usr/bin/env python3
"""
PyPlayer

Class should have the following attributes:

    playlists: an initially empty list, holding the palylists that this player
    has. Each palylist in this list is a list of strings where each string is a
    track name.

    selected_playlist: a list in self.playlists which is selected by user.
    Initially it is None.

    current_track: a string in selected_playlist which is the name of the track
    that is currently being played. Initially it is None.

    status: a string which is either 'off', 'on' 'stop', 'play'. Initially it
    is set to 'off'.

Sample Input

['player0']
[('turn_on', [0]), ('create_empty_playlist', [0]), ('select_playlist', [0, 0]), ('add_track', [0, 'Mon Amore']), ('add_track', [0, 'Yesterday']), ('play', [0, 1]), ('stop', [0])]

Sample Output

[status: on, playlists: [], selected_pl: None, current_track: None, (True, status: on, playlists: [[]], selected_pl: None, current_track: None), (True, status: on, playlists: [[]], selected_pl: [], current_track: None), (True, status: on, playlists: [['Mon Amore']], selected_pl: ['Mon Amore'], current_track: None), (True, status: on, playlists: [['Mon Amore', 'Yesterday']], selected_pl: ['Mon Amore', 'Yesterday'], current_track: None), (True, status: play, playlists: [['Mon Amore', 'Yesterday']], selected_pl: ['Mon Amore', 'Yesterday'], current_track: Yesterday), (True, status: stop, playlists: [['Mon Amore', 'Yesterday']], selected_pl: ['Mon Amore', 'Yesterday'], current_track: None)]
"""

from ast import literal_eval
from copy import deepcopy


class PyPlayer:
    """
    PyPlayer Class
    """
    def __init__(self):
        """
        Parameter-less Constructor
        """

        self.status = "off"
        self.playlists = []
        self.selected_playlist = None
        self.current_track = None

    def turn_on(self):
        """
        Turn on the Player
        """

        self.status = "on"
        self.selected_playlist = None
        self.current_track = None

    def turn_off(self):
        """
        Turn off the Player
        """

        self.status = "off"
        self.selected_playlist = None
        self.current_track = None

    def create_empty_playlist(self):
        """
        Create an Empty Playlist
        """

        if self.status in ["off", "play"]:
            return False

        self.playlists.append([])
        return True

    def select_playlist(self, playlist_index):
        """
        Select a Playlist

        playlist_index: index of playlist in self.playlists
        """

        if self.status in ["off", "play"] \
                or playlist_index >= len(self.playlists):
            return False

        self.selected_playlist = self.playlists[playlist_index]
        return True

    def add_track(self, track_name):
        """
        Add a Track

        track_name: a track name
        """

        if self.status in ["off", "play"] or self.selected_playlist is None:
            return False

        self.selected_playlist.append(track_name)
        return True

    def play(self, track_index):
        """
        Play!

        track_index: index of a track in self.selected_playlist
        """

        if self.status in ["off", "play"] \
                or self.selected_playlist is None \
                or track_index >= len(self.selected_playlist):
            return False

        self.current_track = self.selected_playlist[track_index]
        self.status = "play"
        return True

    def stop(self):
        """
        Stop
        """

        if self.status != "play":
            return False

        self.current_track = None
        self.status = "stop"
        return True

    def __repr__(self):
        """
        Stringify the Player
        """

        return f"status: {self.status}, playlists: {self.playlists}, " + \
               f"selected_pl: {self.selected_playlist}, " + \
               f"current_track: {self.current_track}"


def main():
    """
    Entry Point
    """

    raw_objs = literal_eval(input())
    tests = literal_eval(input())
    objects = [PyPlayer() for e in raw_objs]
    out = []

    for method, args in tests:
        obj = objects[args[0]]

        if method == "turn_on":
            obj.turn_on()
            res = deepcopy(obj)

        elif method == "turn_off":
            obj.turn_off()
            res = deepcopy(obj)

        elif method == "create_empty_playlist":
            ret = obj.create_empty_playlist()
            res = (ret, deepcopy(obj))

        elif method == "select_playlist":
            p_idx = args[1]
            ret = obj.select_playlist(p_idx)
            res = (ret, deepcopy(obj))

        elif method == "add_track":
            tname = args[1]
            ret = obj.add_track(tname)
            res = (ret, deepcopy(obj))

        elif method == "play":
            tindex = args[1]
            ret = obj.play(tindex)
            res = (ret, deepcopy(obj))

        elif method == "stop":
            ret = obj.stop()
            res = (ret, deepcopy(obj))

        out += [res]

    print(out)


if __name__ == "__main__":
    main()
