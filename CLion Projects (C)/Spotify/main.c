#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <string.h>
//#region typedef
typedef struct track {
    char *nome;
    char *id;
    double acousticness;
    double danceability;
    double energy;
    double instrumentalness;
    double liveness;
    double loudness;
    double speechiness;
    double tempo;
    int time_signature;
} Track;

typedef struct artista {
    char *nome;
    char *id;
    double poularidadeTot;
    double qntTrack;
} Artista;

typedef struct album {
    char *nome;
    char *id;
    char *data;
    long duracao;
    int popularidade;
} Album;

typedef struct albumList {
    Track *tracks;
    Album *albuns;
    Artista *Artistas;
    int qntArtistas;
    int qntAlbuns;
    int totalTracks;
} AlbumList;
//#endregion
//#region creates
Album createAlbum() {
    Album a = {
            .duracao = 0,
    };
    return a;
}

Track createTrack() {
    Track t = {
            .acousticness       = 0.0,
            .danceability       = 0.0,
            .energy             = 0.0,
            .instrumentalness   = 0.0,
            .liveness           = 0.0,
            .loudness           = 0.0,
            .speechiness        = 0.0,
            .tempo              = 0.0,
            .time_signature     = 0
    };
    return t;
}

Artista createArtista() {
    Artista a = {
            .poularidadeTot = 0,
            .qntTrack       = 0
    };
    return a;
}

AlbumList createALbumList() {
    AlbumList al = {
            .albuns         = 0,
            .Artistas       = 0,
            .tracks         = 0,
            .qntArtistas    = 0,
            .qntAlbuns      = 0,
            .totalTracks    = 0
    };
    return al;
}
//#endregion
int comp(const void *a, const void *b) {
    Artista a1 = (*((Artista *) a)), a2 = (*((Artista *) b));

    return (a1.poularidadeTot / a1.qntTrack) - (a2.poularidadeTot / a2.qntTrack);
}

int main() {
    char *line = readline(stdin);
    FILE *file = fopen(line, "r");
    free(line);
    line = readline(file);
    free(line);
    AlbumList albuns = createALbumList();
    while (!feof(file)) {
        line = readline(file);
        if (line[0] == '\0')
            break;

        //#region LEITURA
        StringBuilder resul = strSPT(line,"; ",-1);
        Album album = createAlbum();
        Track track = createTrack();
        Artista artista = createArtista();
        track.nome = resul.strings[0];
        track.id = resul.strings[1];
        album.nome = resul.strings[2];
        album.id = resul.strings[3];
        album.data = resul.strings[6];
        album.duracao = atoi(resul.strings[7]);
        album.popularidade = atoi(resul.strings[8]);
        track.acousticness = atof(resul.strings[9]);
        track.danceability = atof(resul.strings[10]);
        track.energy = atof(resul.strings[11]);
        track.instrumentalness = atof(resul.strings[12]);
        track.liveness = atof(resul.strings[13]);
        track.loudness = atof(resul.strings[14]);
        track.speechiness = atof(resul.strings[15]);
        track.tempo = atof(resul.strings[16]);
        track.time_signature = atoi(resul.strings[17]);
        artista.nome = resul.strings[4];
        artista.id = resul.strings[5];
        //#endregion

        //#region SEARCH
        int j = 0, found = 0, artistfound = 0;
        for (int i = 0; i < albuns.qntAlbuns; i++) {
            if (!strcmp(albuns.albuns[i].id, album.id)) {
                found++;
                for (int k = albuns.qntArtistas - 1; k >= 0; k--) {
                    if (!strcmp(albuns.Artistas[k].id, artista.id)) {
                        albuns.Artistas[k].poularidadeTot += album.popularidade;
                        albuns.Artistas[k].qntTrack++;
                        artistfound++;
                        break;
                    }
                }
                break;
            } else if (j < albuns.qntArtistas && !strcmp(albuns.Artistas[j].id, artista.id)) {
                albuns.Artistas[j].poularidadeTot += album.popularidade;
                artistfound++;
            } else {
                j++;
            }
        }
        //#endregion

        //#region ADD DATA
        // caso n tenha encontrado o album
        if (!found) {
            albuns.albuns = realloc(albuns.albuns, ++albuns.qntAlbuns * sizeof(Album));
            albuns.albuns[albuns.qntAlbuns - 1] = album;
            albuns.albuns[albuns.qntAlbuns - 1].id = strdup(album.id);
            albuns.albuns[albuns.qntAlbuns - 1].nome = strdup(album.nome);
            albuns.albuns[albuns.qntAlbuns - 1].data = strdup(album.data);
        }
        //caso n tenha encontrado o artista
        if (!artistfound) {
            albuns.Artistas = realloc(albuns.Artistas, ++albuns.qntArtistas * sizeof(Artista));
            albuns.Artistas[albuns.qntArtistas - 1] = createArtista();
            albuns.Artistas[albuns.qntArtistas - 1].nome = strdup(artista.nome);
            albuns.Artistas[albuns.qntArtistas - 1].poularidadeTot += album.popularidade;
            albuns.Artistas[albuns.qntArtistas - 1].id = strdup(artista.id);
            albuns.Artistas[albuns.qntArtistas - 1].qntTrack++;
        }
        // sempre adiciona a track
        albuns.tracks = realloc(albuns.tracks, ++albuns.totalTracks * sizeof(Track));
        albuns.tracks[albuns.totalTracks - 1] = track;
        albuns.tracks[albuns.totalTracks - 1].nome = strdup(track.nome);
        albuns.tracks[albuns.totalTracks - 1].id = strdup(track.id);
        //#endregion

        //#region FREE
        freeStringBuilder(resul);
        free(line);
        //#endregion

    }
    qsort(albuns.Artistas, albuns.qntArtistas, sizeof(Artista), comp);
    for (int j = 0; j < albuns.qntArtistas; j++) {
        printf("(%d) Artista: %s, Musicas: %.0f musicas, Popularidade: %.2lf, Link: https://open.spotify.com/artist/%s\n",
               1 + j, albuns.Artistas[j].nome, albuns.Artistas[j].qntTrack,
               albuns.Artistas[j].poularidadeTot / albuns.Artistas[j].qntTrack, albuns.Artistas[j].id);
        free(albuns.Artistas[j].nome);
        free(albuns.Artistas[j].id);
    }

    //#region FREE 2.0
    for (int i = 0; i < albuns.totalTracks; i++) {
        if (i < albuns.qntAlbuns) {
            free(albuns.albuns[i].data);
            free(albuns.albuns[i].nome);
            free(albuns.albuns[i].id);
        }
        free(albuns.tracks[i].id);
        free(albuns.tracks[i].nome);
    }
    free(albuns.tracks);
    free(albuns.albuns);
    free(albuns.Artistas);
    //#endregion
}
