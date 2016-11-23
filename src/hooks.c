
#include <fdf.h>
#include <mlx.h>

int				expose(t_mdata *mdata)
{
	if (mdata->iptr)
		mlx_destroy_image(mdata->mptr, mdata->iptr);
	mdata->iptr = mlx_new_image(mdata->mptr, mdata->w, mdata->h);
	mdata->idata = mlx_get_data_addr(mdata->iptr, &mdata->bpp,
										&mdata->sizeline, &mdata->endian);
	draw_map(mdata);
	mlx_put_image_to_window(mdata->mptr, mdata->wptr, mdata->iptr, 0, 0);
	if (mdata->debug)
		debug(mdata);
	return (0);
}

static void		loop_rotate(t_mdata *md, char *check)
{
	if (md->keys->more_angle && (*check = 1))
	{
		md->angle += .1;
		md->x -= 1;
	}
	else if (md->keys->less_angle && (*check = 1))
	{
		md->angle -= .1;
		md->x += 1;
	}
	if (md->keys->rot_z == 1 && (*check = 1))
	{
		if (md->scale_y <= md->scale_x && md->scale_y > -md->scale_x)
			md->scale_y -= .1;
	}
	else if (md->keys->rot_z == -1 && (*check = 1))
	{
		if (md->scale_y >= -md->scale_x - 1 && md->scale_y < md->scale_x)
			md->scale_y += .1;
	}
}

static void		loop_transform(t_mdata *mdata, char *check)
{
	if (mdata->keys->more_height && (*check = 1))
		mdata->height += .01;
	else if (mdata->keys->less_height && (*check = 1))
		mdata->height -= .01;
	if (mdata->keys->zoom && (*check = 1))
	{
		mdata->scale_x += .1;
		mdata->scale_y += .1;
	}
	else if (mdata->keys->unzoom && (*check = 1))
	{
		mdata->scale_x -= .1;
		mdata->scale_y -= .1;
	}
}

static void		loop_move(t_mdata *mdata, char *check)
{
	if (mdata->keys->up && (*check = 1))
		mdata->y -= 1;
	else if (mdata->keys->down && (*check = 1))
		mdata->y += 1;
	if (mdata->keys->left && (*check = 1))
		mdata->x -= 1;
	else if (mdata->keys->right && (*check = 1))
		mdata->x += 1;
}

int				loop(t_mdata *mdata)
{
	char		check;
	char		state;

	check = 0;
	loop_transform(mdata, &check);
	loop_rotate(mdata, &check);
	loop_move(mdata, &check);
	if (check)
	{
		state = mdata->shadows;
		mdata->shadows = 0;
		expose(mdata);
		mdata->shadows = state;
	}
	else
		expose(mdata);
	return (0);
}
